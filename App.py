import os
from tkinter import *
from tkinter import ttk
from tkinter import messagebox
import tkinter.filedialog
import math
import json

# Fonction pour ouvrir un fichier via une boîte de dialogue
def ouvrir_fichier():
    fichier = tkinter.filedialog.askopenfilename(defaultextension=".json", filetypes=[("JSON files", "*.json"), ("All files", "*.*")])
    if fichier:
        global mode_actuel, type_arete
        # Crée un nouvel onglet
        frame = Frame(notebook)
        notebook.add(frame, text=os.path.splitext(os.path.basename(fichier))[0])  # Nom de l'onglet sans extension
        canvas = Canvas(frame, bg="white")
        canvas.pack(fill=BOTH, expand=True)  # Remplit toute la zone disponible dans l'onglet
        donnees_canvas[canvas] = {'sommets': [], 'aretes': [], 'sommets_selectionnes': [], 'type_arete': None}  # Initialise les données du canvas
        lier_clic_souris(canvas)  # Lie les clics de souris au canvas
        mode_actuel = None
        type_arete = None
        with open(fichier, 'r') as f:
            data = json.load(f)
            # Charger les données dans le canvas actuel
            canvas = frame.winfo_children()[0]
            donnees_canvas[canvas] = data
            type_arete = data['type_arete']
            # Effacer le canvas actuel
            canvas.delete("all")
            # Recréer les sommets
            nbr = 0
            for sommet in data['sommets']:
                id_sommet, x, y = sommet
                canvas.create_oval(x - 10, y - 10, x + 10, y + 10, fill="lightblue")
                canvas.create_text(x, y, text=str(nbr))
                nbr=nbr+1
            # Recréer les arêtes
            for arete in data['aretes']:
                sommet1, sommet2 = arete
                x1, y1 = sommet1[1], sommet1[2]
                x2, y2 = sommet2[1], sommet2[2]
                # Rayon des sommets (cercles)
                radius = 10

                # Calcul du vecteur de direction entre les deux sommets
                dx, dy = x2 - x1, y2 - y1
                distance = math.sqrt(dx ** 2 + dy ** 2)

                if distance == 0:
                    return  # Évite une division par zéro si les centres des sommets sont identiques

                # Normalisation du vecteur de direction
                dx /= distance
                dy /= distance
                # Calcul des points d'intersection sur les périmètres des sommets
                x1_edge = x1 + dx * radius
                y1_edge = y1 + dy * radius
                x2_edge = x2 - dx * radius
                y2_edge = y2 - dy * radius
                if data['type_arete'] == "non_oriente":
                    canvas.create_line(x1_edge, y1_edge, x2_edge, y2_edge, fill="black", width=2)
                else:
                    canvas.create_line(x1_edge, y1_edge, x2_edge, y2_edge, fill="black", width=2, arrow=LAST)

def enregistrer_fichier():
    fichier = tkinter.filedialog.asksaveasfilename(defaultextension=".json", filetypes=[("JSON files", "*.json"), ("All files", "*.*")])
    if fichier:
        canvas = notebook.nametowidget(notebook.select()).winfo_children()[0]
        data = donnees_canvas[canvas]
        with open(fichier, 'w') as f:
            json.dump(data, f)
        # Change the tab name to the saved file name
        notebook.tab(notebook.select(), text=os.path.splitext(os.path.basename(fichier))[0]) # Nom de l'onglet sans extension

# Fonction pour créer une nouvelle tab avec un canvas dédié
def creer_nouvelle_fenetre():
    global mode_actuel, type_arete
    # Crée un nouvel onglet
    frame = Frame(notebook)
    notebook.add(frame, text="Sans-titre")  # Nom de l'onglet
    canvas = Canvas(frame, bg="white")
    canvas.pack(fill=BOTH, expand=True)  # Remplit toute la zone disponible dans l'onglet
    donnees_canvas[canvas] = {'sommets': [], 'aretes': [], 'sommets_selectionnes': [], 'type_arete': None}  # Initialise les données du canvas
    lier_clic_souris(canvas)  # Lie les clics de souris au canvas
    mode_actuel = None
    type_arete = None

# Fonction pour fermer l'onglet actif
def fermer_fenetre():
    if notebook.index("end") > 0:
        notebook.forget(notebook.select())

# Fonction pour créer un sommet (cercle) sur le canvas
def creer_sommet(event, canvas):
    global mode_actuel
    if mode_actuel == "sommet":
        donnees = donnees_canvas[canvas]
        x, y = event.x, event.y  # Coordonnées du clic de souris

        # Vérifie si un sommet existe déjà à proximité
        for sommet in donnees['sommets']:
            _, x_sommet, y_sommet = sommet
            if (x_sommet - 20 <= x <= x_sommet + 20) and (y_sommet - 20 <= y <= y_sommet + 20):
                messagebox.showerror("Erreur", "Un sommet existe déjà à cet endroit.")
                return

        id_sommet = len(donnees['sommets'])  # ID unique pour chaque sommet
        sommet = canvas.create_oval(x - 10, y - 10, x + 10, y + 10, fill="lightblue")  # Dessine un cercle
        texte = canvas.create_text(x, y, text=str(id_sommet))  # Ajoute un numéro au centre du cercle
        donnees['sommets'].append((sommet, x, y))  # Ajoute le sommet aux données

# Fonction pour sélectionner un sommet existant sur le canvas
def selectionner_sommet(event, canvas):
    global mode_actuel
    if mode_actuel == "arete":
        donnees = donnees_canvas[canvas]
        x, y = event.x, event.y  # Coordonnées du clic de souris
        for sommet in donnees['sommets']:
            id_sommet, x_sommet, y_sommet = sommet
            # Vérifie si le clic est à l'intérieur du cercle
            if (x_sommet - 10 <= x <= x_sommet + 10) and (y_sommet - 10 <= y <= y_sommet + 10):
                donnees['sommets_selectionnes'].append(sommet)
                canvas.itemconfig(id_sommet, fill="lightgreen")  # Change la couleur du sommet sélectionné
                # Si deux sommets sont sélectionnés, crée une arête entre eux
                if len(donnees['sommets_selectionnes']) == 2:
                    creer_arete(canvas)

# Fonction pour créer une arête entre deux sommets (orientée ou non)
def creer_arete(canvas):
    global type_arete
    donnees = donnees_canvas[canvas]
    if len(donnees['sommets_selectionnes']) == 2:
        sommet1, sommet2 = donnees['sommets_selectionnes']
        x1, y1 = sommet1[1], sommet1[2]  # Coordonnées du premier sommet
        x2, y2 = sommet2[1], sommet2[2]  # Coordonnées du second sommet

        # Rayon des sommets (cercles)
        radius = 10

        # Calcul du vecteur de direction entre les deux sommets
        dx, dy = x2 - x1, y2 - y1
        distance = math.sqrt(dx ** 2 + dy ** 2)

        if distance == 0:
            return  # Évite une division par zéro si les centres des sommets sont identiques

        # Normalisation du vecteur de direction
        dx /= distance
        dy /= distance

        # Calcul des points d'intersection sur les périmètres des sommets
        x1_edge = x1 + dx * radius
        y1_edge = y1 + dy * radius
        x2_edge = x2 - dx * radius
        y2_edge = y2 - dy * radius

        # Dessine l'arête selon le type (orientée ou non orientée)
        if type_arete == "non_oriente":
            canvas.create_line(x1_edge, y1_edge, x2_edge, y2_edge, fill="black", width=2)
        else:
            # Dessine une flèche pour les arêtes orientées
            canvas.create_line(x1_edge, y1_edge, x2_edge, y2_edge, fill="black", width=2, arrow=LAST)

        # Ajoute l'arête aux données du canvas
        donnees['aretes'].append((sommet1, sommet2))
        donnees['type_arete'] = type_arete

        # Remet les sommets sélectionnés à leur couleur d'origine
        canvas.itemconfig(sommet1[0], fill="lightblue")
        canvas.itemconfig(sommet2[0], fill="lightblue")

        # Réinitialise la sélection des sommets
        donnees['sommets_selectionnes'].clear()

# Fonction pour gérer les clics de souris sur le canvas
def clic_souris(event, canvas):
    global mode_actuel
    if mode_actuel == "sommet":
        creer_sommet(event, canvas)
    elif mode_actuel == "arete":
        selectionner_sommet(event, canvas)

# Fonction pour lier les clics de souris au canvas
def lier_clic_souris(canvas):
    canvas.bind("<Button-1>", lambda event: clic_souris(event, canvas))

# Fonction pour définir le mode de création des sommets
def definir_mode_sommet():
    global mode_actuel
    mode_actuel = "sommet"

# Fonction pour définir le mode de création des arêtes non orientées
def definir_mode_arete_non_oriente():
    global mode_actuel, type_arete
    mode_actuel = "arete"
    if type_arete is None:
        type_arete = "non_oriente"
    elif type_arete != "non_oriente":
        messagebox.showerror("Erreur","Vous ne pouvez pas créer des arêtes non orientées dans ce canvas.")

# Fonction pour définir le mode de création des arêtes orientées
def definir_mode_arete_oriente():
    global mode_actuel, type_arete
    mode_actuel = "arete"
    if type_arete is None:
        type_arete = "oriente"
    elif type_arete != "oriente":
        messagebox.showerror("Erreur","Vous ne pouvez pas créer des arêtes orientées dans ce canvas.")

# Define the functions to show the matrices
def show_adjacency_matrix():
    # Code to display the adjacency matrix
    canvas = notebook.nametowidget(notebook.select()).winfo_children()[0]
    data = donnees_canvas[canvas]
    sommets = data['sommets']
    aretes = data['aretes']
    
    # Initialize the adjacency matrix with zeros
    n = len(sommets)
    adjacency_matrix = [[0] * n for _ in range(n)]
    
    # Fill the adjacency matrix
    for arete in aretes:
        sommet1, sommet2 = arete
        i = sommets.index(sommet1)
        j = sommets.index(sommet2)
        adjacency_matrix[i][j] = 1
        if data['type_arete'] == "non_oriente":
            adjacency_matrix[j][i] = 1
    
    # Display the adjacency matrix at the bottom of the main window
    for widget in fenetre_principale.pack_slaves():
        if isinstance(widget, Frame) and widget.winfo_name() == "matrix_frame":
            widget.destroy()
    
    matrix_frame = Frame(fenetre_principale, name="matrix_frame")
    matrix_frame.pack(side=BOTTOM, fill=X)
    
    label = Label(matrix_frame, text="Matrice d'adjacence:", borderwidth=1, relief="solid")
    label.pack()
    
    for i in range(n):
        row_frame = Frame(matrix_frame)
        row_frame.pack()
        for j in range(n):
            cell = Label(row_frame, text=str(adjacency_matrix[i][j]), borderwidth=1, relief="solid", width=3)
            cell.pack(side=LEFT)

def show_incidence_matrix():
    # Code to display the incidence matrix
    canvas = notebook.nametowidget(notebook.select()).winfo_children()[0]
    data = donnees_canvas[canvas]
    sommets = data['sommets']
    aretes = data['aretes']
    
    # Initialize the incidence matrix with zeros
    n = len(sommets)
    m = len(aretes)
    incidence_matrix = [[0] * m for _ in range(n)]
    
    # Fill the incidence matrix
    for k, arete in enumerate(aretes):
        sommet1, sommet2 = arete
        i = sommets.index(sommet1)
        j = sommets.index(sommet2)
        incidence_matrix[j][k] = 1
        if data['type_arete'] == "non_oriente":
            incidence_matrix[i][k] = 1
        else:
            incidence_matrix[i][k] = -1
    
    # Display the incidence matrix at the bottom of the main window
    for widget in fenetre_principale.pack_slaves():
        if isinstance(widget, Frame) and widget.winfo_name() == "matrix_frame":
            widget.destroy()
    
    matrix_frame = Frame(fenetre_principale, name="matrix_frame")
    matrix_frame.pack(side=BOTTOM, fill=X)
    
    label = Label(matrix_frame, text="Matrice d'incidence:", borderwidth=1, relief="solid")
    label.pack()
    
    for i in range(n):
        row_frame = Frame(matrix_frame)
        row_frame.pack()
        for j in range(m):
            cell = Label(row_frame, text=str(incidence_matrix[i][j]), borderwidth=1, relief="solid", width=3)
            cell.pack(side=LEFT)

# Determiner si ce graphe possede une chaine/cycle eulerienne
def chaine_eulerienne():
    canvas = notebook.nametowidget(notebook.select()).winfo_children()[0]
    data = donnees_canvas[canvas]
    sommets = data['sommets']
    aretes = data['aretes']
    n = len(sommets)
    m = len(aretes)

    # Initialise les degrés entrants et sortants pour chaque sommet
    in_degrees = [0] * n
    out_degrees = [0] * n
    
    for sommet1, sommet2 in aretes:
        i = sommets.index(sommet1)
        j = sommets.index(sommet2)
        
        if data['type_arete'] == "non_oriente":
            # Pour un graphe non orienté, on incrémente le degré pour les deux sommets
            in_degrees[i] += 1
            in_degrees[j] += 1
        else:
            # Pour un graphe orienté, on utilise les degrés entrants et sortants
            out_degrees[i] += 1
            in_degrees[j] += 1

    # Vérification de la connexité du graphe
    visited = [False] * n
    stack = [0]
    visited[0] = True
    while stack:
        i = stack.pop()
        for sommet1, sommet2 in aretes:
            u = sommets.index(sommet1)
            v = sommets.index(sommet2)
            if u == i and not visited[v]:
                visited[v] = True
                stack.append(v)
            elif v == i and not visited[u] and data['type_arete'] == "non_oriente":
                visited[u] = True
                stack.append(u)

    if not all(visited):
        messagebox.showinfo("Chaine Eulerienne", "Ce graphe n'est pas connexe, donc il ne possède pas de chaîne/cycle eulérien.")
        return

    # Vérification des conditions pour les chaînes/cycles eulériens
    if data['type_arete'] == "non_oriente":
        odd_degree_count = sum(1 for degree in in_degrees if degree % 2 != 0)
        
        if odd_degree_count == 0:
            messagebox.showinfo("Chaine Eulerienne", "Ce graphe possède un cycle eulérien.")
        elif odd_degree_count == 2:
            messagebox.showinfo("Chaine Eulerienne", "Ce graphe possède une chaîne eulérienne.")
        else:
            messagebox.showinfo("Chaine Eulerienne", "Ce graphe ne possède pas de chaîne/cycle eulérien.")
    else:
        start_nodes = end_nodes = 0
        for i in range(n):
            if out_degrees[i] - in_degrees[i] == 1:
                start_nodes += 1
            elif in_degrees[i] - out_degrees[i] == 1:
                end_nodes += 1
            elif in_degrees[i] != out_degrees[i]:
                messagebox.showinfo("Chaine Eulerienne", "Ce graphe ne possède pas de chaîne/cycle eulérien.")
                return

        if start_nodes == 0 and end_nodes == 0:
            messagebox.showinfo("Chaine Eulerienne", "Ce graphe possède un cycle eulérien.")
        elif start_nodes == 1 and end_nodes == 1:
            messagebox.showinfo("Chaine Eulerienne", "Ce graphe possède une chaîne eulérienne.")
        else:
            messagebox.showinfo("Chaine Eulerienne", "Ce graphe ne possède pas de chaîne/cycle eulérien.")

# Depth-First Search with adjacency list
def parcours_profondeur():
    canvas = notebook.nametowidget(notebook.select()).winfo_children()[0]
    data = donnees_canvas[canvas]
    sommets = data['sommets']
    aretes = data['aretes']
    
    # Create an adjacency list
    adjacency_list = {i: [] for i in range(len(sommets))}
    for sommet1, sommet2 in aretes:
        i = sommets.index(sommet1)
        j = sommets.index(sommet2)
        adjacency_list[i].append(j)
        if data['type_arete'] == "non_oriente":
            adjacency_list[j].append(i)
    
    visited = [False] * len(sommets)
    order = []

    # Recursive DFS function
    def dfs(v):
        visited[v] = True
        order.append(v)
        for neighbor in adjacency_list[v]:
            if not visited[neighbor]:
                dfs(neighbor)
    
    # Start DFS from the first vertex
    dfs(0)

    # Display traversal order
    for widget in fenetre_principale.pack_slaves():
        if isinstance(widget, Frame) and widget.winfo_name() == "order_frame":
            widget.destroy()

    order_frame = Frame(fenetre_principale, name="order_frame")
    order_frame.pack(side=BOTTOM, fill=X)

    label = Label(order_frame, text="Ordre de parcours en profondeur: " + ", ".join(map(str, order)), borderwidth=1, relief="solid")
    label.pack()

# Breadth-First Search with adjacency list
def parcours_largeur():
    canvas = notebook.nametowidget(notebook.select()).winfo_children()[0]
    data = donnees_canvas[canvas]
    sommets = data['sommets']
    aretes = data['aretes']
    
    # Create an adjacency list
    adjacency_list = {i: [] for i in range(len(sommets))}
    for sommet1, sommet2 in aretes:
        i = sommets.index(sommet1)
        j = sommets.index(sommet2)
        adjacency_list[i].append(j)
        if data['type_arete'] == "non_oriente":
            adjacency_list[j].append(i)

    visited = [False] * len(sommets)
    order = []
    queue = [0]
    visited[0] = True

    # BFS traversal
    while queue:
        v = queue.pop(0)
        order.append(v)
        for neighbor in adjacency_list[v]:
            if not visited[neighbor]:
                visited[neighbor] = True
                queue.append(neighbor)

    # Display traversal order
    for widget in fenetre_principale.pack_slaves():
        if isinstance(widget, Frame) and widget.winfo_name() == "order_frame":
            widget.destroy()

    order_frame = Frame(fenetre_principale, name="order_frame")
    order_frame.pack(side=BOTTOM, fill=X)

    label = Label(order_frame, text="Ordre de parcours en largeur: " + ", ".join(map(str, order)), borderwidth=1, relief="solid")
    label.pack()

# Dictionnaire pour stocker les données associées à chaque canvas
donnees_canvas = {}
# Variable pour stocker le mode actif (création de sommets ou d'arêtes)
mode_actuel = None
# Variable pour stocker le type d'arête (orientée ou non orientée)
type_arete = None

# Création de la fenêtre principale de l'application
fenetre_principale = Tk()
fenetre_principale.title("Interface Graphique")
fenetre_principale.geometry("1600x800")

# Création d'un Notebook (pour les onglets)
notebook = ttk.Notebook(fenetre_principale)
notebook.pack(fill=BOTH, expand=True)

# Création du menu principal
menu = Menu(fenetre_principale)
fenetre_principale.config(menu=menu)

# Menu "fichier" pour gérer les fichiers
menu_fichier = Menu(menu, tearoff=0)
menu.add_cascade(label='fichier', menu=menu_fichier)
menu_fichier.add_command(label="Nouveau", command=creer_nouvelle_fenetre)  # Crée une nouvelle fenêtre/canvas
menu_fichier.add_command(label="Ouvrir", command=ouvrir_fichier)  # Ouvre un fichier
menu_fichier.add_command(label="Enregistrer", command=enregistrer_fichier)  # Enregistre un fichier
menu_fichier.add_separator()  # Séparateur dans le menu
menu_fichier.add_command(label="Fermer", command=fermer_fenetre)  # Ferme uniquement l'onglet actif
menu_fichier.add_command(label="Quitter", command=fenetre_principale.quit)  # Quitte l'application

menu_creation = Menu(menu, tearoff=0)
menu.add_cascade(label='Creation', menu=menu_creation)

# Ajout des commandes pour les sommets et arêtes directement dans "Ajouter"
menu_creation.add_command(label="Sommets", command=definir_mode_sommet)  # Crée des sommets

menu_graphe_Aretes = Menu(menu_creation, tearoff=0)
menu_graphe_Aretes.add_command(label="Non oriente", command=definir_mode_arete_non_oriente)  # Mode arêtes non orientées
menu_graphe_Aretes.add_command(label="Oriente", command=definir_mode_arete_oriente)  # Mode arêtes orientées
menu_creation.add_cascade(label='Aretes', menu=menu_graphe_Aretes)

# Menu "affichage" (à définir si nécessaire)
menu_affichage = Menu(menu, tearoff=0)
menu.add_cascade(label='affichage', menu=menu_affichage)

# Add a submenu to the "affichage" menu for matrices
menu_matrice = Menu(menu_affichage, tearoff=0)
menu_affichage.add_cascade(label='Matrice', menu=menu_matrice)

# Add commands to the "matrice" submenu
menu_matrice.add_command(label="Matrice d'adjacence", command=show_adjacency_matrix)
menu_matrice.add_command(label="Matrice d'incidence", command=show_incidence_matrix)


# Menu "exécution" (à définir si nécessaire)
menu_execution = Menu(menu, tearoff=0)
menu.add_cascade(label='exécution', menu=menu_execution)
menu_execution.add_command(label="Chaine Eulerienne", command=chaine_eulerienne)
menu_parcours = Menu(menu_execution, tearoff=0)
menu_parcours.add_command(label="Parcours en profondeur", command=parcours_profondeur)
menu_parcours.add_command(label="Parcours en largeur", command=parcours_largeur)
menu_execution.add_cascade(label='Parcours', menu=menu_parcours)



# Menu "édition" (à définir si nécessaire)
menu_edition = Menu(menu, tearoff=0)
menu.add_cascade(label='édition', menu=menu_edition)

# Boucle principale de l'application
fenetre_principale.mainloop()

import turtle

# Initialisation de la fenêtre Turtle
wn = turtle.Screen()
wn.bgcolor("white")
wn.title("Ma maison")

# Initialisation de la tortue
t = turtle.Turtle()
t.speed(0)
t.pensize(2)

# Dessin de la maison
t.penup()
t.goto(-150, -150)
t.pendown()
t.forward(300)
t.left(90)
t.forward(200)
t.left(90)
t.forward(300)
t.left(90)
t.forward(200)
t.left(90)

# Dessin du toit
t.penup()
t.goto(-150, 50)
t.pendown()
t.left(45)
t.forward(212)
t.right(90)
t.forward(212)
t.right(45)

# Dessin de la porte
t.penup()
t.goto(-50, -150)
t.pendown()
t.fillcolor("brown")
t.begin_fill()
t.forward(100)
t.left(90)
t.forward(150)
t.left(90)
t.forward(100)
t.left(90)
t.forward(150)
t.end_fill()

# Dessin des fenêtres
t.penup()
t.goto(-130, -50)
t.pendown()
t.fillcolor("lightblue")
t.begin_fill()
t.forward(60)
t.left(90)
t.forward(60)
t.left(90)
t.forward(60)
t.left(90)
t.forward(60)
t.end_fill()

t.penup()
t.goto(70, -50)
t.pendown()
t.fillcolor("lightblue")
t.begin_fill()
t.forward(60)
t.left(90)
t.forward(60)
t.left(90)
t.forward(60)
t.left(90)
t.forward(60)
t.end_fill()

# Fermeture de la fenêtre Turtle
wn.mainloop()

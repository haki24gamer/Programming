<?php
    //Connexion
    $serveur = "localhost";
    $utilisateur = "root";
    $motdepasse = "";
    $base = "gestion_etudiant";
    $conn = "";

    $conn = mysqli_connect("$serveur","$utilisateur","$motdepasse","$base");

    //Variables
    $num = $_POST["Numero"];
    $nom = $_POST["Nom"];
    $mdp = $_POST["MotDePasse"];
    $sexe = $_POST["Sexe"];
    $email = $_POST["Email"];
    $adresse = $_POST["Adresse"];
    $filiere = $_POST["Numfil"];

    
    $sql = "UPDATE Etudiant SET numero_etudiant = '$num', nom_etudiant = '$nom', mot_passe_etudiant = '$mdp', sexe_etudiant = '$sexe', email_etudiant = '$email', adresse_etudiant = '$adresse', num_filiere = '$filiere' WHERE numero_etudiant = '$num'";


    $insertion = mysqli_query($conn,$sql);

    
?>

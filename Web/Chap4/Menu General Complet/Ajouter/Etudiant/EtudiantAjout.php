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

    $sql = "INSERT INTO Etudiant VALUES ('$num', '$nom', '$mdp', '$sexe', '$email', '$adresse', '$filiere')";

    $insertion = mysqli_query($conn,$sql);+

    mysqli_close($conn);
?>

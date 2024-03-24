<?php
    //Connexion
    $serveur = "localhost";
    $utilisateur = "root";
    $motDePasse = "";
    $base = "gestion_etudiant";

    //Recuperation
    $num_filiere = $_POST["NumeroFiliere"];
    $nom_filiere = $_POST["NomFiliere"];

    mysql_query("INSERT INTO filiere VALUES ('$num_filiere','$nom_filiere')");
?>
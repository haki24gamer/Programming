<?php
    //Connexion
    $serveur = "localhost";
    $utilisateur = "root";
    $motDePasse = "";
    $base = "gestion_etudiant";

    //Recuperation
    $num_filiere = $_POST["NumeroFiliere"];
    $nom_filiere = $_POST["NomFiliere"];
    
    mysqli_query($con,"INSERT INTO filiere VALUES ('$num_filiere','$nom_filiere')") or die(mysqli_error($con));
?>
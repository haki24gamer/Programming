<?php

    //Connexion
    $serveur = "localhost";
    $utilisateur = "root";
    $motdepasse = "";
    $base = "gestion_etudiant";

    $conn = mysqli_connect("$serveur","$utilisateur","$motdepasse","$base");

    //Recuperation
    $nom = $_POST["Nom"];
    $mdp = $_POST["MDP"];

    //Creation du requete
    $sql = "SELECT * FROM Etudiant WHERE nom_etudiant='$nom' and mot_passe_etudiant='$mdp'";

    $result = mysqli_query($conn, $sql);

    if (mysqli_num_rows($result)>0) {
        header("Location: ../Menu General Complet/Menu.html");
    }
    else{
        echo "Le nom de compte ou le mot de passe est incorrecte";
    }
?>

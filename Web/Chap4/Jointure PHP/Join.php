<?php
    //Connexion
    $serveur = "localhost";
    $utilisateur = "root";
    $motdepasse = "";
    $base = "gestion_etudiant";
    $conn = "";

    $conn = mysqli_connect("$serveur","$utilisateur","$motdepasse","$base");

    //Recuperation
    $nom = $_POST["Nom"];


    //Creation de la requete
    $sql = "SELECT *
            FROM Etudiant
            WHERE num_filiere in
                (SELECT num_filiere
                FROM Filiere
                WHERE Filiere.nom_filiere = '$nom')
            ";

    //Parcours
    $result = mysqli_query($conn, $sql);

    //Affichage
    while ($ligne=mysqli_fetch_row($result)) {
        echo ("$ligne[0], $ligne[1], $ligne[2], $ligne[3], $ligne[4], $ligne[5], $ligne[6], $ligne[7] <br>");
    }
    
?>
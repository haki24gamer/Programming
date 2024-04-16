<?php

    //Connexion
    $serveur = "localhost";
    $utilisateur = "root";
    $motdepasse = "";
    $base = "gestion_etudiant";

    $conn = mysqli_connect("$serveur","$utilisateur","$motdepasse","$base");


    $sql = "SELECT * FROM Filiere";

    $result = mysqli_query($conn, $sql);

    while ($ligne=mysqli_fetch_row($result)) {
        echo ("$ligne[0], $ligne[1] <br>");
    }

?>
<?php

    $serveur = "localhost";
    $utilisateur = "root";
    $motdepasse = "";
    $base = "gestion_etudiant";
    $conn = "";

    $conn = mysqli_connect("$serveur","$utilisateur","$motdepasse","$base");

    $nom = $_POST["Nom"];


    $sql = "SELECT Module.* 
	    FROM Enseignant, Module
        WHERE Enseignant.numero_enseignant=Module.numero_enseignant
        and Enseignant.nom_enseignant='$nom'
        ";

    $result = mysqli_query($conn, $sql);

    echo"
        <table border=1>
        <tr>
            <td>Code de module</td>
            <td>Nom de module</td>
            <td>Coeff de module</td>
            <td>Volume Horaire</td>
            <td>Numero de l enseignant</td>
            <td>Nom de l enseignant</td>
        </tr>
    ";

    while ($ligne=mysqli_fetch_row($result)) {
        echo ("
    
        <tr>
            <td>$ligne[0]</td>
            <td>$ligne[1]</td>
            <td>$ligne[2]</td>
            <td>$ligne[3]</td>
            <td>$ligne[4]</td>
            <td>$nom</td>
        </tr>
    "
    );
    }

    echo"

        </table>
    ";
    


?>
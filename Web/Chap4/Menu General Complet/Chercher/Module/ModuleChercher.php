<?php
    //Connexion
    $serveur = "localhost";
    $utilisateur = "root";
    $motdepasse = "";
    $base = "gestion_etudiant";
    $conn = "";

    $conn = mysqli_connect("$serveur","$utilisateur","$motdepasse","$base");

    //Variables
    $num = $_POST["Code"];

    $sql = "SELECT * FROM Module where code_module = '$num'";

    $result = mysqli_query($conn, $sql);

    $ligne = mysqli_fetch_row($result);

    echo ("
    <table border=1>
        <tr>
            <td>Code</td>
            <td>Nom</td>
            <td>Coeff</td>
            <td>Volumae Horaire</td>
            <td>Numero de l enseignant</td>
        </tr>
        <tr>
            <td>$ligne[0]</td>
            <td>$ligne[1]</td>
            <td>$ligne[2]</td>
            <td>$ligne[3]</td>
            <td>$ligne[4]</td>
        </tr>
    </table>
    "
    );
    
?>
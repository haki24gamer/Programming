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

    $sql = "SELECT * FROM Note where num_note = '$num'";

    $result = mysqli_query($conn, $sql);

    $ligne = mysqli_fetch_row($result);

    echo ("
    <table border=1>
        <tr>
            <td>Numero</td>
            <td>Controle Continue</td>
            <td>Controle Finale</td>
            <td>Semestre</td>
            <td>Annee</td>
            <td>Numero de l etudiant</td>
            <td>Code de module</td>
        </tr>
        <tr>
            <td>$ligne[0]</td>
            <td>$ligne[1]</td>
            <td>$ligne[2]</td>
            <td>$ligne[3]</td>
            <td>$ligne[4]</td>
            <td>$ligne[5]</td>
            <td>$ligne[6]</td>
        </tr>
    </table>
    "
    );
?>
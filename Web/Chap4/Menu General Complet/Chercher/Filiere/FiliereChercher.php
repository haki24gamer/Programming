
<?php

    //Connexion
    $serveur = "localhost";
    $utilisateur = "root";
    $motdepasse = "";
    $base = "gestion_etudiant";

    $conn = mysqli_connect("$serveur","$utilisateur","$motdepasse","$base");


    $num = $_POST["Numero"];


    $sql = "SELECT * FROM Filiere where num_filiere = '$num'";

    $result = mysqli_query($conn, $sql);

    $ligne = mysqli_fetch_row($result);

    
    echo ("
    <table border=1>
        <tr>
            <td>Numero</td>
            <td>Nom</td>
        </tr>
        <tr>
            <td>$ligne[0]</td>
            <td>$ligne[1]</td>
        </tr>
    </table>
    "
    );

?>

<?php

    //Connexion
    $serveur = "localhost";
    $utilisateur = "root";
    $motdepasse = "";
    $base = "gestion_etudiant";

    $conn = mysqli_connect("$serveur","$utilisateur","$motdepasse","$base");


    $num = $_POST["Numero"];


    $sql = "SELECT * FROM Etudiant where numero_etudiant = '$num'";

    $result = mysqli_query($conn, $sql);

    $ligne = mysqli_fetch_row($result);

    echo ("
    <table border=1>
        <tr>
            <td>Numero</td>
            <td>Nom et Prenom</td>
            <td>Mot de passe</td>
            <td>Sexe</td>
            <td>Filiere</td>
            <td>Email</td>
            <td>Adresse</td>
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
<?php
    //Connexion
    $serveur = "localhost";
    $utilisateur = "root";
    $motdepasse = "";
    $base = "gestion_etudiant";
    $conn = mysqli_connect("$serveur","$utilisateur","$motdepasse","$base");


    $filiere = $_POST["Filiere"];

    $sql = "SELECT Etudiant.* FROM Etudiant,Filiere where Etudiant.num_filiere=Filiere.num_filiere and Filiere.nom_filiere='$filiere'";
    $Recherche = mysqli_query( $conn,$sql);


    echo "
        <table border=1 width=50% cellpadding=10px>
            <tr>
            <td>Numero</td>
            <td>Nom et Prenom</td>
            <td>Mot de passe</td>
            <td>Sexe</td>
            <td>Filiere</td>
            <td>Email</td>
            <td>Adresse</td>
        </tr>allah
        
        </table>
    ";
    while ($ligne = mysqli_fetch_row($Recherche)) {
        echo "
            <table border=1 width=50% cellpadding=10px>
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
        ";
    }
?>
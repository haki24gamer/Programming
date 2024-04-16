<?php
    //Connexion
    $serveur = "localhost";
    $utilisateur = "root";
    $motdepasse = "";
    $base = "gestion_etudiant";
    $conn = "";

    $conn = mysqli_connect("$serveur","$utilisateur","$motdepasse","$base");

    //Variables
    $numfil = $_POST["Numero"];
    $nomfil = $_POST["Nom"];

    $sql = "INSERT INTO Filiere VALUES ('$numfil','$nomfil')";
 
    $ajouter = mysqli_query($conn, $sql);

    mysqli_close($conn);
    
?>
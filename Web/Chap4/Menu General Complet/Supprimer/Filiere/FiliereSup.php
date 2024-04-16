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

    $sql = "DELETE FROM Etudiant WHERE numero_etudiant = '$num'";
 
    $ajouter = mysqli_query($conn, $sql);

    mysqli_close($conn);
    
?>
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

    $sql = "DELETE FROM Module WHERE code_module = '$num'";
 
    $ajouter = mysqli_query($conn, $sql);

    mysqli_close($conn);
    
?>
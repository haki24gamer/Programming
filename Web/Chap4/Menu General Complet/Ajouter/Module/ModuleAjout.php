<?php
    //Connexion
    $serveur = "localhost";
    $utilisateur = "root";
    $motdepasse = "";
    $base = "gestion_etudiant";
    $conn = "";

    $conn = mysqli_connect("$serveur","$utilisateur","$motdepasse","$base");

    //Variables
    $code = $_POST["Code"];
    $nom = $_POST["Nom"];
    $coeff = $_POST["Coeff"];
    $volhor = $_POST["VolHor"];
    $numens = $_POST["NumEns"];

    $sql = "INSERT INTO Module VALUES ('$code','$nom','$coeff','$volhor','$numens')";
 
    $ajouter = mysqli_query($conn, $sql);

    mysqli_close($conn);
    
?>
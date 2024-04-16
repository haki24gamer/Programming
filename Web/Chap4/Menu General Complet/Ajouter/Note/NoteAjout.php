<?php
    //Connexion
    $serveur = "localhost";
    $utilisateur = "root";
    $motdepasse = "";
    $base = "gestion_etudiant";
    $conn = "";

    $conn = mysqli_connect("$serveur","$utilisateur","$motdepasse","$base");

    //Variables
    $num = $_POST["Num"];
    $cc = $_POST["CC"];
    $cf = $_POST["CF"];
    $sem = $_POST["Semestre"];
    $annee = $_POST["Annee"];
    $numet = $_POST["NumEt"];
    $codemod = $_POST["CodeModule"];

    $sql = "INSERT INTO Note VALUES ('$num','$cc','$cf','$sem','$annee','$numet','$codemod')";
 
    $ajouter = mysqli_query($conn, $sql);

    mysqli_close($conn);
    
?>
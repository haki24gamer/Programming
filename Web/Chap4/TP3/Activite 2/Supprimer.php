<?php
    //Connexion
    $serveur = "localhost";
    $utilisateur = "root";
    $motdepasse = "";
    $base = "iad";
    $conn = "";

    $conn = mysqli_connect("$serveur","$utilisateur","$motdepasse","$base");



    //Variables
    $num = $_POST["Numero"];

    $suppresion = "DELETE FROM etudiant WHERE numero_etudiant='$num'";


    mysqli_query($conn,$suppresion);


    mysqli_close($conn);
?>
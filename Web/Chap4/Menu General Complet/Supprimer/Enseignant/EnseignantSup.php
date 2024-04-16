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

    $sql = "DELETE FROM Enseignant WHERE numero_enseignant = '$num'";
 
    $ajouter = mysqli_query($conn, $sql);

    mysqli_close($conn);
    
?>
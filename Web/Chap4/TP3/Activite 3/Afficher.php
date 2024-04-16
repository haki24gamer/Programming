<?php
    //Connexion
    $serveur = "localhost";
    $utilisateur = "root";
    $motdepasse = "";
    $base = "iad";
    $conn = "";

    $conn = mysqli_connect("$serveur","$utilisateur","$motdepasse","$base");



    //Variables
    $sql = "SELECT * FROM etudiant";

    $afficher=mysqli_query($conn,$sql);

    while ($ligne = mysqli_fetch_row($afficher)) {
        echo $ligne[0].", ".$ligne[1].", ".$ligne[2].", ".$ligne[3].", ".$ligne[4].", ".$ligne[5].", ".$ligne[6]."<br>";
    }
    
    echo "<a href='../Activite 5/Menu.html'><button>Retourner</button></a>";
    
    mysqli_close($conn);
?>
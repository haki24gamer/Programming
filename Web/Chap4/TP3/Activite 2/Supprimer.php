<?php
    //Connexion
    $serveur = "localhost";
    $utilisateur = "root";
    $motdepasse = "";
    $base = "iad";
    $conn = "";

    $conn = mysqli_connect("$serveur","$utilisateur","$motdepasse","$base");



    //Variables
    $numero_etudiant = $_POST["Numero"];

    $suppresion = "DELETE FROM etudiant WHERE numero_etudiant='$numero_etudiant'";


    mysqli_query($conn,$suppresion);

    
    echo "<a href='../Activite 5/Menu.html'><button>Retourner</button></a>";


    mysqli_close($conn);

?>
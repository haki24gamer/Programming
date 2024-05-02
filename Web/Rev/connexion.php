<?php
//Connexion
$serveur="localhost";
$utilisateur="root";
$motdepasse="";
$base="gestion_etudiant";
$conn = mysqli_connect("$serveur","$utilisateur","$motdepasse","$base");

//Recuperation
$Nom=$_POST["Nom"];
$Pass=$_POST["Password"];

//Parcours
$sql = "SELECT * FROM Etudiant WHERE nom_etudiant='$Nom' and mot_passe_etudiant='$Pass'";
$requete = mysqli_query($conn,$sql);

if (mysqli_num_rows($requete)>0) {
    header("Location: menu.html");
}
else {
    echo"Nom ou motdepasse errone";
}

?>
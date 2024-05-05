<html>
<head>
</head>
<title> exemple d’application sur php </title>


<?php

/* connection a la base de donnees   */

$serveur     = "localhost";
$utilisateur = "root";
$motDePasse  = "";
$base        = "mesn";


   $sum=mysqli_connect($serveur, $utilisateur , $motDePasse, $base  ) ;
   

/*  affichage de la requête */

$requet = "SELECT * FROM etudiant";
$result = mysqli_query($sum,"SELECT * FROM etudiant");
echo"
<center><h1>Rechercher un Etudiant</h1><br><br><br><br>
<table border=1>
<tr><td>Numero </td><td>Nom et Prenom </td><td>Mot de passe</td> <td>Sexe</td> <td>Filiere</td><td>Email</td> <td>Adresse</td></tr>";
	while($ligne = mysqli_fetch_row($result)) {
$numero= $ligne[0];
 $nom= $ligne[1];
$pass = $ligne[2]; 
$sexe = $ligne[3]; 
$filiere = $ligne[4];	
$email = $ligne[5]; 	
$adresse = $ligne[6]; 
	echo "<tr><td>$numero</td><td>$nom</td><td>$pass</td><td>$sexe</td><td>$filiere</td><td>$email</td><td>$adresse</td></tr> ";
	}

echo "</table><br><br><br><a href='menugeneral.html'> Retour au Menu Generale </a>";
?>

</html>


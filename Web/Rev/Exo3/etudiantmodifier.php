
<html>
<head>
</head>
<title> exemple d�application sur php </title>
<?php

/* connection a la base de donnees */

$serveur     = "localhost";
$utilisateur = "root";
$motDePasse  = "";
$base        = "gestion_etudiant";



   $sum=mysqli_connect($serveur, $utilisateur ,$motDePasse,$base );


/* r�cup�ration des donn�es envoy�s par le formulaire */

$numero    = $_POST["numero"];
$nom    = $_POST["nom"];
$passe    = $_POST["passe"];
$sexe    = $_POST["sexe"];
$filiere    = $_POST["filiere"];
$email    = $_POST["email"];
$adresse  = $_POST["adresse"];

/*  Cr�ation de la requ�te */

$resultat = mysqli_query($sum, "UPDATE  etudiant
SET     nom_etudiant  =  '$nom', passe_etudiant  =  '$passe' ,sexe_etudiant  =  '$sexe', filiere_etudiant  =  '$filiere', email_etudiant  =  '$email', adresse_etudiant  =  '$adresse'
WHERE numero_etudiant=$numero");
			  
			  if($resultat==0)
			  { echo "les donnees ne sont pas bien modifies";
			  }
			  else 
				  { echo "les donnees  sont  bien modifies <br>"; 
			  echo '<a href="menugeneral.html"> Retour au Menu Generale </a>';
			  }
				  
				  

?>
</html>
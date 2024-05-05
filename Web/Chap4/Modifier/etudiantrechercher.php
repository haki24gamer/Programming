
<?php

$serveur     = "localhost";
$utilisateur = "root";
$motDePasse  = "";
$base        = "gestion10_etudiant";


 $sum=mysqli_connect($serveur, $utilisateur ,$motDePasse,$base );

 /*récupération des données envoyés par le formulaire */

$numero    = $_POST["numero"];

   
	
    $result = mysqli_query($sum,"select * from etudiant where numero_etudiant=$numero");
	while($ligne= mysqli_fetch_row ($result)) {
 
 
 $numero= $ligne[0];
 $nom= $ligne[1];
$pass = $ligne[2]; 
$sexe = $ligne[3]; 
$filiere = $ligne[4];	
$email = $ligne[5]; 	
$adresse = $ligne[6];
 ?>
 <center>Inscription des Etudiants en ligne <br><br>
 <form action="etudiantmodifier.php" method="POST" >
<table border=1>
<tr><td>Numero :<td><input name='numero' type='text' size='30' value="<?php echo "$numero" ?>"></td></tr>
<tr><td>Nom : <td><input name='nom' type='text' size='30' value="<?php echo "$nom" ?>"></td></tr>
<tr><td>Mot de passe :<td><input name='passe' type='password' size='30' value="<?php echo "$pass" ?>"></td></tr>
<tr><td>Sexe :<td><input type="radio" name="sexe"  value="masculin" <?php      if ( $sexe =="masculin") echo "checked" ?>> M 
<input type="radio" name="sexe"  value="feminin"  <?php      if ( $sexe =="feminin") echo "checked" ?>>F </td></tr>

<tr><td>Filiere :<td><input type="radio" name="filiere" value="informatique" <?php if ( $filiere =="informatique") echo "checked" ?>> Informatique 
<input type="radio" name="filiere" value="comptabilite" <?php if ( $filiere =="comptabilite") echo "checked" ?>>Comptabilite
<input type="radio" name="filiere" value="logistique" <?php if ( $filiere =="logistique") echo "checked" ?>>Logistique</td></tr>
<tr><td>Email : <td><input name="email" type="text" size="30"    value="<?php echo "$email" ?>">  </td></tr>
<tr><td>Adresse :<td><textarea rows="4" name="adresse" cols="50"    > <?php echo "$adresse" ?></textarea></td></tr>

<tr><td></td><td><input type="reset" value="Annuler"><input type="submit" value="Modifier"></td></tr>
<table>
</center>

</form>
<?php
 
 }

?>


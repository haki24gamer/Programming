<?php

    //Connexion
    $serveur="localhost";
    $utilisateur="root";
    $motdepasse="";
    $base="gestion_etudiant";

    $conn = mysqli_connect("$serveur","$utilisateur","$motdepasse","$base");

    //Recuperation
    $Num = $_POST["Numero"];

    //Parcours
    $sql = "SELECT * FROM Etudiant where numero_etudiant = '$Num'";

    $result = mysqli_query($conn, $sql);

    $ligne = mysqli_fetch_row($result);

    

    //Affichage
    //$ligne[0]
    $Nom=$ligne[1];
    $Mot=$ligne[2];
    $Sexe=$ligne[3];
    $Email=$ligne[4];
    $Adresse=$ligne[5];
    $Filiere=$ligne[6];
    
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form method="post" action="EtudiantAjout.php">
        <table border="1">
            <tr>
                <td>Numero:</td>
                <td><input type="number" name="Numero" value="<?php echo $Num; ?>"></td>
            </tr>
            <tr>
                <td>Nom et prenom:</td>
                <td><input type="text" name="Nom" value="<?php echo $Nom; ?>"></td>
            </tr>
            <tr>
                <td>Mot de passe:</td>
                <td><input type="password" name="MotDePasse" value="<?php echo $Mot; ?>"></td>
            </tr>
            <tr>
                <td>Sexe:</td>
                <td>
                    <?php
                        if ($Sexe=="Masculin") {
                            echo "
                            <input type='radio' name='Sexe' value='Masculin' checked> M
                            <input type='radio' name='Sexe' value='Feminin'> F
                            ";
                        } else {
                            echo "
                            <input type='radio' name='Sexe' value='Masculin'> M
                            <input type='radio' name='Sexe' value='Feminin' checked> F
                            ";
                        }
                        
                    ?>
                </td>
            </tr>
            <tr>
                <td>Email:</td>
                <td><input type="email" name="Email" value="<?php echo $Email; ?>"></td>
            </tr>
            <tr>
                <td>Adresse:</td>
                <td><input type="text" name="Adresse" value="<?php echo $Adresse; ?>"></td>
            </tr>
            <tr>
                <td>Filiere:</td>
                <td>
                    <input type="number" name="Numfil"  value="<?php echo $Filiere; ?>">
                </td>
            </tr>
            <tr>
                <td></td>
                <td>
                    <input type="reset" value="Annuler">
                    <input type="submit" value="Modifier">
                </td>
            </tr>
        </table>
    </form>
</body>
</html>
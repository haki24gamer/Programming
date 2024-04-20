<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>BD_etudiant</title>
</head>

<body>


    <?php
    // Partie Connection 
    include 'Connexion.php';
    if (!$connect) {
        die("Erreur: " . mysqli_connect_error());
    }
    echo "Connecté <br>";

    // Partie Recupération de données
    $Num = $_POST["Num"];
    $num_etudiant = $_POST["numero"];
    $nom_etudiant = $_POST["Nom"];
    $mdp = $_POST["mdp"];
    $sexe = $_POST["Sexe"];
    $num_fili = $_POST["num_filiere"];
    $email = $_POST["Email"];
    $Niveau_filiere = $_POST["Niveau_filiere"];
    $adresse = $_POST["Adresse"];

    $sql = "UPDATE Etudiant SET num_etudiant = '$num_etudiant',nom_etudiant = '$nom_etudiant',mot_passe = '$mdp',sexe_etudiant = '$sexe',email_etudiant = '$email', adresse_etudiant = '$adresse', niveau_etudiant = '$Niveau_filiere', num_filiere = '$num_fili' WHERE num_etudiant = '$Num'";


    if (mysqli_query($connect, $sql)) {
        echo "Nouveau enregistrement effectué";
    } else {
        echo "Erreur: " . $sql . "<br>" . mysqli_error($connect);
    }

    // Fermeture de la connection 
    mysqli_close($connect);

    ?>

</body>

</html>
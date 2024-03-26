<?php
    $num=$_POST["Numero"];
    echo "le numero est: ", $num;

    $nom=$_POST["Nom"];
    echo "<br>le nom est: ", $nom;

    $motdepasse=$_POST["MotDePasse"];
    echo "<br>le mot de passe est: ", $motdepasse;

    $sexe = $_POST["Sexe"];
    echo "<br>le sexe est: ", $sexe;

    $filiere = $_POST["Filiere"];
    echo "<br>la filiere est: ", $filiere;

    $email = $_POST["Email"];
    echo "<br>la email est: ", $email;

    $adresse = $_POST["Adresse"];
    echo "<br>l adresse est: ", $adresse;
?>
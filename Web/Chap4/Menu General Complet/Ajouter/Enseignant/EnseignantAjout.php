<?php
    //Connexion
    $serveur="localhost";
    $utilisateur= "root";
    $motdepasse="";
    $base="gestion_etudiant";

    $conn = mysqli_connect("$serveur","$utilisateur","$motdepasse","$base");

    //Variable
    $num=$_POST["NumEns"];
    $nom=$_POST["NomEns"];
    $sexe=$_POST["SexeEns"];
    $email=$_POST["EmailEns"];
    $adresse=$_POST["AdresseEns"];
    $tel=$_POST["TelEns"];
    $grade=$_POST["GradeEns"];
    $motdepasse=$_POST["MDPEns"];
    

    //requete
    $sql = "INSERT INTO Enseignant VALUES ('$num', '$nom', '$sexe', '$email', '$adresse', '$tel', '$grade', '$motdepasse')";
    $sql = "INSERT INTO Enseignant VALUES ('$num', '$nom', '$sexe', '$email', '$adresse', '$tel', '$grade', '$motdepasse')";

    $ajouter = mysqli_query($conn,$sql);

    mysqli_close( $conn );
?>
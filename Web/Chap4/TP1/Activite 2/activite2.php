<?php
    $name = $_POST["Nom"];
    $motdepasse = $_POST["mot_de_passe"];

    if ($motdepasse=="Math") {
            
        echo "Votre nom est: ", $name;
        echo "<br>";
        echo "Votre mot de passe est: ", $motdepasse;
    }
    else {
        echo "Desole ",$name,", Votre mot de passe est incorrect";
    }
    

?>

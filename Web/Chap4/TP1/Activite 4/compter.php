<?php
    $val1 = $_POST["valeur1"];
    $nb = strlen($val1);
    $som=0;

    for ($i=0; $i < $nb; $i++) { 
        $som = $som+$i;
    }

    echo "le nom est $val1, le nombre des caracteres est de $nb. Et la somme de caractere est $som";
?>
<?php
    $val1 = $_POST["valeur1"];
    $op = $_POST["Operateurs"];
    $val2 = $_POST["valeur2"];

    if ($op == "plus") {
        $res = $val1+$val2;
        echo $res;
    }
    if ($op == "moins") {
        $res = $val1-$val2;
        echo $res;
    }
    if ($op == "fois") {
        $res = $val1*$val2;
        echo $res;
    }
    if ($op == "division") {
        $res = $val1/$val2;
        echo $res;
    }
?>
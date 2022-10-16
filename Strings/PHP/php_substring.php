<?php

$myString = 'ohey! php is the greatest!';
substr($myString, 1); // starts from the second characters (index 1), which means "o" is skipped at the start.

echo $myString; // returns: "hey! php is the greatest!"
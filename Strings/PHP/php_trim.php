<?php

$stringToTrim = 'test php is awesome';
$result = trim($stringToTrim, 'test'); // removes a specific word/character from a string, and returns the result.

echo $result; // returns: "php is awesome"

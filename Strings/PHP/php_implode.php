<?php

$myArray = [
    'BMW',
    'Audi',
    'Mercedes',
    'Toyota',
    'Porsche'
];

$implodedString = implode(', ', $myArray); // splits array up into a string, where each element is split by ", ".

echo $implodedString; // returns: "BMW, Audi, Mercedes, Toyota, Porsche"

<?php

$conn = new mysqli(
    "localhost",
    "root", // Root dir /opt/lampp/htdocs/
    "", // Password
    "kalika" // Database
);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
?>

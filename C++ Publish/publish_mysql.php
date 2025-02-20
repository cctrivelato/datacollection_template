<?php
// Database Credentials (editable)
$host = "local";
$dbname = "test";
$username = "admin";
$password = "*****";

// Metrics name (editable)
$data1_name = isset($_POST['data1_name']) ? $_POST['data1_name'] : '';

// Metrics values (editable name and quantity)
$data1 = isset($_POST['data1']) ? $_POST['data1'] : '';

// Table name (editable name and quantity)
$table = isset($_POST['table']) ? $_POST['table'] : '';

$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

// Insert data into the table
$sql = "INSERT INTO $table ($data1_name) 
        VALUES ('$data1')";

if ($conn->query($sql) === TRUE) {
  echo "New record created successfully";
} else {
  echo "Error: " . $sql . "<br>" . $conn->error;
}

// Close the connection
$conn->close();
?>
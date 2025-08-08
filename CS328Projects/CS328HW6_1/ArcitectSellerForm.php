<!--ArchitectSellerForm.php-->
<!doctype html>
<html>

<head>

	<link rel="stylesheet" type= "text/css" href="./hw2style.css">
	<meta name="author" content="Daniel Desforges, djd86@humboldt.edu" />

	<meta name="description" content="HSU CS328, "/>

	<meta name="keywords" content="CS 328,
	HSU, Humboldt, Humboldt
	State, Humboldt State University, California State University, Arcata,
	California,Homework,Web Apps" />
          
	<title> Project6_1phpCS328</title>
</head>

<?php
$first = $_POST["firstN"];
$last = $_POST["lastN"];
$height = $_POST["height"];
$rooms = $_POST["rooms"];
$descript = $_POST["descript"];
$hirerate = $_POST["hirerate"];
$remote = $_POST["remote"];
$onsite = $_POST["onsite"];
$timestamp = $_getTimestamp["first"];

echo "<p> Form Stamp First $first Last $last Email Phone Height $height Rooms $rooms Descript $descript Remote? $remote Onsite? $onsite TimeStamp </p>";

?>
</html>
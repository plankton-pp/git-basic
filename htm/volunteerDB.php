<?php
	// connect to the database
	$conn=mysqli_connect("localhost", "root", "","volunteerhub");
	$conn->query("SET NAMES UTF8");
	// get results from database
	if (isset($_GET["search"])&&$_GET["search"]<>"") {
		 $search = $_GET["search"];
		 $sql="SELECT * FROM volunteer WHERE type LIKE '%$search%'";
	} else {
		 $sql="SELECT * FROM volunteer";
	}
	$rs=$conn->query($sql);
	while($row = $rs->fetch_assoc()) {
		echo $row['type'];
	 // echo out the contents of each row into a table
	$conn->close(); // close database connection
?>
<?php
	//checks if the user is authorized
	session_start();
	if (!isset($_SESSION['user_name'])) {
		echo 'Not a user!';
		header("Location: http://{$_SERVER['HTTP_HOST']}/n8623392/login.php");
		exit(); 
	}
?>
<?php
	$pdo = new PDO('mysql:host=localhost;dbname=php', 'root', 'password');
	$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
?>
<?php
/*
	*Checks whether an entry in the database matches the username 
	*and password entered by the user
	*Parameters: *$username = $_POST['username']
	*$password = $_POST['password']
*/
	function checkPassword($username, $password) {
		require '/inc/Database/database-connection.inc';

		$stmt = $pdo->prepare("SELECT username, admin FROM users ".
		"WHERE username = :username and password = SHA2(CONCAT(:password, salt), 0)");
		$stmt->bindValue(':username', $username);
		$stmt->bindValue(':password', $password);
		$stmt->execute();
		$result = $stmt->fetch();
		
		/*if there is an entry in the database that matches what was entered by the user, a session is started, 
		otherwise a message 'Login Failed' is displayed on the page'*/
		if($stmt->rowCount() > 0){
			echo 'yes';
			session_start(); 
			$_SESSION['user_name'] = $username;
			$_SESSION['user_type'] = $result['admin'];
			header("Location: http://".$_SERVER['HTTP_HOST']."/n8623392/home.php");
			exit();			
		} else {
			echo '<fieldset>'; 
			echo 'Login Failed!';
			echo '</fieldset>';
		}	
		$pdo = null;
	}//end checkPassword

?>

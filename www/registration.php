<?php
	echo '<!DOCTYPE html>';
	echo '<html>';
		echo '<head>';
			echo '<title>Registration</title>';
			echo '<link href="header-footer.css" rel="stylesheet" type="text/css"/>';
			echo '<script type="text/javascript" src="/n8623392/js/registration-validation.js"></script>';
		echo '</head>';
		//javascript validation is enabled when the page loads
		echo '<body onload="initialise()">';
			echo '<div id="wrapper">';
				require '/inc/header-and-menu.inc'; 
				require '/inc/Registration/input-field.inc';
	
	//stores any error messages from functions in registration-validate.inc
	$errors = array();
	
	//when the user presses the submit button, php validation is run
	if (isset($_POST['submit'])) { 
		require '/inc/Registration/registration-validate.inc';
			validateUsername($errors, $_POST, 'username');
			validateEmail($errors, $_POST, 'email');
			validateDOB ($errors, $_POST, 'DOB');
			validatePassword1 ($errors, $_POST, 'pwd1');
			validatePassword2 ($errors, $_POST, $_POST, 'pwd1', 'pwd2');
			validateGender ($errors, $_POST, 'gender', 'Female');
			validateCheckbox ($errors, $_POST, 'terms');
		
		//if form contains any errors a message will appear
		if ($errors) { 
			echo '<fieldset>';
				echo 'Registration failed, please correct the following errors:';
			echo '</fieldset>';
				// then redisplays the form
				require '/inc/Registration/registration-form.inc';
		}
		else {	
		//if submission successful inserts the values in the fields to the database
			require '/inc/Database/database-connection.inc';
			//salts the password and adds unique salt for each user
			$sql = "INSERT INTO users (username, email, dob, password, gender, salt) ".
			"VALUES (:username, :email, :dob, SHA2(CONCAT(:password, :salt), 0), :gender, :salt)";
				$stmt = $pdo->prepare($sql);
				$stmt->bindValue(':username', $_POST['username']);
				$stmt->bindValue(':password', $_POST['pwd1']);
				$stmt->bindValue(':email', $_POST['email']);
				$stmt->bindValue(':dob', $_POST['DOB']);
				$stmt->bindValue(':gender', $_POST['gender']);
				$stmt->bindValue(':salt', uniqid());
				$stmt->execute();
				$pdo = null;
					echo '<fieldset id="SuccessMessage">';
						echo 'Form submitted successfully with no errors'; 
					echo '</fieldset>';
		}	 
	}
	else {
		require '/inc/Registration/registration-form.inc';
	}
				include '/inc/footer.inc'; 
			echo '</div>'; //wrapper
		echo '</body>';

	echo '</html>';
?>


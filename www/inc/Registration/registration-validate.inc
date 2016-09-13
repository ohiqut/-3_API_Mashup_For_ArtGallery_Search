<?php
/*	
	*Validates Username field
	*Parameters: $errors = error message (e.g *Your Username is required*)
	*$field_list = $_POST 
	*$field_name = 'username'
*/
function validateUsername(&$errors, $field_list, $field_name) {
	$pattern = '/^[a-zA-Z0-9_-]+$/';
	
	//if user has not entered anything in the field, an error message will appear.
	if (!isset($field_list[$field_name])|| empty($field_list[$field_name])) {
		$errors[$field_name] = '<br/> *Your Username is required*';
	}	
	//if the length of the username is less than 5 characters long, an error message will appear.
	else if (strlen($field_list[$field_name]) < 5) {
		$errors[$field_name] = '<br/> *Usernames must be at least 5 characters long*';
	}	
	//if the username entered does not match the Regex, an error message will appear.
	else if (!preg_match($pattern, $field_list[$field_name])) {
		$errors[$field_name] = '<br/> *Usernames can only include upper and lowercase letters,<br/> numbers, underscores (_) or hyphens (-)*';
	}
	//checks the database whether a username has already been used
	else {
		require '/inc/Database/database-connection.inc';	
		$stmt = $pdo->prepare("SELECT username FROM users WHERE username = :username");
		$stmt->bindValue(':username', $field_list[$field_name]);
		$result = $stmt->execute();
		 
			if($stmt->rowCount() > 0){
				$errors[$field_name] = '<br/> *Username already exists*';
			} 
			$pdo = null;
		}
}//end validateUsername

/*
    *Validates Email field
    *Parameters: $errors = error message
    *$field_list = $_POST 
    *$field_name = 'email'
*/
function validateEmail(&$errors, $field_list, $field_name) {
	//allows for .edu.au or similar type emails in addition to standard emails e.g somename@hotmail.com
	$pattern = '/[a-zA-Z0-9\.\-]+@[a-zA-Z0-9\-]+\.[a-z]{2,3}(\.[a-z]{2,3})?(\.[a-z]{2})?$/';
	if (!isset($field_list[$field_name])|| empty($field_list[$field_name])) {
		$errors[$field_name] = '<br/> *Your Email is required*';
	}
	else if (!preg_match($pattern, $field_list[$field_name])) {
		$errors[$field_name] = '<br/> *Not a valid Email*';
	}
	//checks the database whether a username has already been used
	else {
		require '/inc/Database/database-connection.inc';	
		$stmt = $pdo->prepare("SELECT email FROM users WHERE email = :email");
		$stmt->bindValue(':email', $field_list[$field_name]);
		$result = $stmt->execute();
		 
			if($stmt->rowCount() > 0){
				$errors[$field_name] = '<br/> *Email already exists*';
			} 
			$pdo = null;
		}
}//end validateEmail

/*
    *Validates DOB field
    *Parameters: $errors = error message
    *$field_list = $_POST 
    *$field_name = 'DOB'
*/
function validateDOB(&$errors, $field_list, $field_name) {
	/*Follows yyyy-mm-dd-format*/
	$pattern = '/^[0-9]{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[0-1])$/'; 
	if (!isset($field_list[$field_name])|| empty($field_list[$field_name])) {
		$errors[$field_name] = '<br/> *Your Date of Birth is required*';
	}
	else if (!preg_match($pattern, $field_list[$field_name])) {
		$errors[$field_name] = '<br/> *Not a valid Date of birth*<br/> *e.g 1992-09-29*';
	}
}// end validateDOB

/*
    *Validates Password field
    *Parameters: $errors = error message 
 	*$field_list = $_POST  
	*$field_name = 'pwd1'
*/
function validatePassword1(&$errors, $field_list, $field_name) {
	$pattern = '/^(?=.*[a-z])(?=.*[A-Z])(?=.*\d).+$/'; 
	if (!isset($field_list[$field_name])|| empty($field_list[$field_name])) {
		$errors[$field_name] = '<br/> *Your Password is required*';
	}
	else if (strlen($field_list[$field_name]) < 6) {
		$errors[$field_name] = '<br/> *Passwords must be at least 6 characters long*';
	}
	else if (!preg_match($pattern, $field_list[$field_name])) {
		$errors[$field_name] = '<br/> *Password must include at least one digit, one upper and<br/>one lower case letter and can include symbols*';
	}
}//end validatePassword1

/*
	*Validates ConfirmPassword field
	*Parameters: $errors = error message
	*$field_list = $_POST
	*$pwd1 = 'pwd1'
	*$confirmpwd = 'pwd2' 
*/
function validatePassword2(&$errors, $field_list, $field_list, $pwd1, $confirmpwd) {
	if (($field_list[$pwd1]) !== ($field_list[$confirmpwd])) {
		$errors[$confirmpwd] = '<br/> *Please enter the same Password as above*';
	}
}//end validatePassword2

/*
	*Validates Gender Radio Buttons
	*Parameters: $errors = error message 
	*$field_list = $_POST 
	*$gender = 'gender'
	*$errorname = 'Female' 
	//error message will only appear once instead of twice if gender was used as an id in the span tag
*/
function validateGender(&$errors, $field_list, $gender, $errorname) {
	if(!isset($field_list[$gender])) {
		$errors[$errorname] = '<br/> *Gender not selected*';
	}
}//end validateGender

/*
	*Validates Terms CheckBox
	*Parameters: $errors = error message 
	*$field_list = $_POST 
	*$field_name = 'terms'
*/
function validateCheckbox (&$errors, $field_list, $field_name) {
	if(!isset($field_list[$field_name])) {
		$errors[$field_name] = '<br/> *Please indicate that you accept the Terms and Conditions*';
	}
}//end validateCheckbox
?>



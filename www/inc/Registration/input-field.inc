<?php
/*Registration Form*/
//Example Registrationform.inc 
//inputField($errors, 'username', 'Username', 'Enter Username');
/*
	*Creates a label tag
	*Parameters: $name = 'username'
	*$label = 'Username'
*/
function label($name, $label){
	echo "<Label for=\"$name\">$label: </Label>";
}//end label

/*
	*Grabs what was entered by the user passes it to the htmlspecialchars function 
	*to avoid cross-site scripting
	*Parameters: $name = 'username'
*/
function postedValue ($name){
	if(isset($_POST[$name])) {
		return htmlspecialchars($_POST[$name]);
	}
}//end postedValue

/*
	*If there are any error messages, display to user
	*Parameters: &$errors = references $errors in input field
	*$name = 'username'
*/
function errorLabel(&$errors, $name) {	
	if(isset($errors[$name])){
		echo "<span id=\"{$name}Error\" class=\"error\"> $errors[$name]</span>";
	}
}//end errorLabel

/*
	*Creates a text field
	*Additional span tag is used to display error messages for javascript validation
	*Parameters: $errors = error message from php validation
	e.g (*Your Username is required*)
	*$name = 'username'
	*$label = 'Username'
	*$placeHolder = 'Enter Username';
*/
function inputField($errors, $name, $label, $placeHolder) {
	echo '<div class="required_field">';
		label($name, $label);
		$value = postedValue($name);
		echo "<input type=\"text\" id=\"$name\" name=\"$name\" size=29 placeHolder=\"$placeHolder\" value=\"$value\"/>"; 
		echo "<span id=\"{$name}jsError\" class=\"error\"></span>";
		errorLabel($errors, $name);
	echo '</div>';
}//end input_field

/*
	*Creates a password field
	*Additional span tag is used to display error messages for javascript validation
	*Parameters: $errors = displays error message from validate functions in Registrationvalidate.inc
	*$name = 'pwd1'
	*$label = 'Password'
	*$placeHolder = 'Enter Password';
*/
function passwordField($errors, $name, $label, $placeHolder) {
	echo '<div class="required_field">';
		label($name, $label);
		$value = postedValue($name);
		echo "<input type=\"password\" id=\"$name\" name=\"$name\" size=29 placeHolder=\"$placeHolder\" value=\"$value\"/>"; 	
		echo "<span id=\"{$name}jsError\" class=\"error\"></span>";
		errorLabel($errors, $name);
	echo '</div>';
}//end password_field

/*
	*Creates a radio button
	*Additional span tag is used to display error messages for javascript validation
	*Parameters: $errors = error message from validate functions in Registrationvalidate.inc
	*$name = 'gender'
	*$label = 'Male'
	*$value = 'M';
*/
function radioButton ($errors, $name, $label, $value) {
	
	echo '<div class="required_field">';
		label($name, $label);
		echo "<input type=\"radio\" id=\"$name\" name=\"$name\" value=\"$value\"/>";
		echo "<span id=\"$label\" class=\"error\"></span>";
		errorLabel($errors, $label);
	echo '</div>';
}//end radioButton

/*
	*Creates a check box
	*Additional span tag is used to display error messages for javascript validation
	*Parameters: $errors = error message from validate functions in Registrationvalidate.inc
	*$name = 'terms'
	*$label = 'I agree to Brisbane Wifi'
	*$page = 'Terms.html';
	*$link = 'terms and conditions.';
*/
function checkBox ($errors, $name, $label, $page, $link) {
	echo '<div class="required_field">';
		echo "<input type=\"checkbox\"  id=\"$name\" name=\"$name\">
		$label <a href=\"$page\">$link</a>";
		echo "<span id=\"{$name}jsError\" class=\"error\"></span>";
		errorLabel($errors, $name);
	echo '</div>';
}//end checkBox

/*
	*Creates a submit button
	*Parameters: $name = 'submit'
	*$value = 'Register';
*/
function submitButton ($name, $value) {
	echo "<input type=\"submit\" id=\"$name\" name=\"$name\" value=\"$value\">";
}//end submitButton

/*Login form*/
/*
	*Creates a login field
	*Parameters: $name = 'username'
	*$label = 'Login'
*/
function loginField($name, $label) {
	echo '<div class="required_field">';
		label($name, $label);
		echo "<input type=\"text\" id=\"$name\" name=\"$name\"/>"; 
	echo '</div>';
}//end loginField

/*
	*Creates a password field
	*Parameters: $name = 'password'
	*$label = 'Password'
*/
function loginPasswordField($name, $label) {
	echo '<div class="required_field">';
	label($name, $label);
	echo "<input type=\"password\" id=\"$name\" name=\"$name\"/>"; 	
	echo '</div>';
}//end loginPasswordField
/*
	*Creates a Login button
	*Parameters: $name = 'login'
	*$value = 'Login';
*/
function loginButton ($name, $value) {
	echo "<input type=\"submit\" id=\"$name\" name=\"$name\" value=\"$value\">";
}//end loginButton

?>
	
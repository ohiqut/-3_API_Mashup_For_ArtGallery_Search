<form action="registration.php" method="post" name="form">
	<fieldset id="Form">
		<?php
			inputField ($errors, 'username', 'Username', 'Enter Username');
			inputField ($errors, 'email', 'Email', 'Enter a valid Email Address');
			inputField ($errors, 'DOB', 'Date of birth', 'yyyy-mm-dd');
			passwordField ($errors, 'pwd1', 'Password', 'Enter Password');
			passwordField ($errors, 'pwd2', 'Confirm Password', 'Re-enter Password');
			radioButton ($errors, 'gender', 'Male', 'M');
			radioButton ($errors, 'gender', 'Female', 'F');
			checkBox ($errors, 'terms', 'I agree to Brisbane Wifi','Terms.html', 'terms and conditions.');
			submitButton ('submit', 'Register');
		?>
	</fieldset>
</form>
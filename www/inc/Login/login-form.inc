<form action="login.php" method="post">
	<fieldset id="Form">
		<?php
			loginField ('username', 'Login');
			loginPasswordField ('password', 'Password');
			loginButton ('login', 'Login');
		?>
	</fieldset>
</form>
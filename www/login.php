<?php
	echo '<!DOCTYPE html>';
	echo '<html>';
		echo '<head>';
			echo '<title>Login</title>';
			echo '<link href="header-footer.css" rel="stylesheet" type="text/css"/>';
		echo '</head>';
		echo '<body>';
			echo '<div id="wrapper">';
				require './inc/header-and-menu.inc';
				require './inc/Registration/input-field.inc';

					//when the login button is clicked by the user, checkPassword is called
					if (isset($_POST['login'])){
						require './inc/Login/validate-login.inc';
						echo'<script>alert("This is just a demo. Login feature will be available soon!")</script>';
						//checkPassword($_POST['username'], $_POST['password']);
					}
					require './inc/Login/login-form.inc';
				include './inc/footer.inc';
			echo '</div>'; //wrapper
		echo '</body>';
	echo '</html>';
?>

<?php
	session_start();
	unset($_SESSION['user_name']);
	session_destroy();
	
	echo '<!DOCTYPE html>';
	echo '<html>';
		echo '<head>';
			echo '<title>Logout</title>';
			echo '<link href="header-footer.css" rel="stylesheet" type="text/css"/>';
		echo '</head>';
		echo '<body>';
			echo '<div id="wrapper">';
			require '/inc/header-and-menu.inc';
				echo '<fieldset id="Messagebox">';
					echo 'You are now logged out!';
				echo '</fieldset>';
			include '/inc/footer.inc';
			echo '</div>'; //wrapper
		echo '</body>';
	echo '</html>';
?>
<?php
	echo '<!DOCTYPE html>';
	echo '<html>';
		echo '<head>';
			echo '<title>Terms and Conditions</title>';
			echo '<link href="header-footer.css" rel="stylesheet" type="text/css"/>';
			echo '</head>';
		echo '<body>';
			echo '<div id="wrapper">';
				//session_start();
				require './inc/header-and-menu.inc'; 
				echo '<fieldset id="Textbox">';
					include './inc/terms.inc';
				echo '</fieldset>';
				include './inc/footer.inc'; 
			echo '</div>'; //wrapper
		echo '</body>';
	echo '</html>';
?>
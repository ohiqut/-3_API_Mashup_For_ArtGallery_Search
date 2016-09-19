<?php
	echo '<!DOCTYPE html>';
	echo '<html>';
		echo '<head>';
			echo '<title>Contact Us</title>';
			echo '<link href="header-footer.css" rel="stylesheet" type="text/css"/>';
		echo '</head>';
		echo '<body>';
			echo '<div id="wrapper">';
				//session_start();
				require './inc/header-and-menu.inc';
				echo '<fieldset id="Textbox">';
					echo '<h1>Contact us</h1>';
					echo '<table>';
						echo '<tr><th>Name</th><td>Ohi Ahmed</td></tr>';
						echo '<tr><th>Student Number</th><td>n9023348</td></tr>';
						echo '<tr><th>Email</th><td>ohi.ahmed@connect.qut.edu.au</td></tr>';	
					echo '</table>';
				echo '</fieldset>';
				include './inc/footer.inc';
			echo '</div>'; //wrapper
		echo '</body>';
	echo '</html>';
?>

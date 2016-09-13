<?php
	require '/inc/Login/authorize-session.inc';
	if ($_SESSION['user_type'] != '1') {
		echo 'Not a user!';
		header("Location: http://{$_SERVER['HTTP_HOST']}/login.php");
		exit(); 
	}
	
	echo '<!DOCTYPE html>';
	echo '<html>';
		echo '<head>';
			echo '<title>Admin</title>';
			echo '<link href="header-footer.css" rel="stylesheet" type="text/css"/>';
		echo '<head>';
		echo '<body>';
			echo '<div id="wrapper">';
				echo '<fieldset>';
					require '/inc/file-upload.inc';
					function createForm() {
						echo '<form action="Admin.php" method="POST" enctype="multipart/form-data">';
							echo 'Upload CSV file: <input type="file" name="file" id="file" size="256"><br/>';
							echo '<input type="submit" value="upload" name="submit">';
						echo '</form>';
					}
				echo '</fieldset>';
			echo '</div>';
		echo '</body>';
	echo '</html>';
?>
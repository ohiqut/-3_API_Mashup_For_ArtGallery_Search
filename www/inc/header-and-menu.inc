<?php
	echo '<div id="userLogin">';
		echo '<menu class="menu">';
			/*if the user is login in, their username is displayed in the header
			and logout link is able to be clicked*/
			if (isset($_SESSION['user_name'])) {
				echo '<span id="user">Hello '.$_SESSION['user_name'].'</span><a href="logout.php">Logout</a>';
			} else {
				echo '<a href="login.php">Login</a>';
				echo '<a href="registration.php">Register</a>';
			}
		echo '</menu>';
	echo '</div>';
	echo '<div id="header">';
		echo '<header>';
			echo '<h1>Brisbane Art Galleries Mash </h1> ';
		echo '</header>';
	echo '</div>';
	echo '<menu class="menu">';
			echo '<a href="home.php">Home</a><a href="search-form.php">Search Form</a>'.
			'<a href="terms-and-conditions.php">Terms & Conditions</a><a href="contact-us.php">Contact Us</a>';
	echo '</menu>';
?>


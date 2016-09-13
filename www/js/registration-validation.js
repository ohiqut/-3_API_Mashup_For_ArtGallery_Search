//Allows javascript validation once the page loads 
//instead of when the user clicks on the submit button
function initialise () {
	var username = document.getElementById("username");
	var email = document.getElementById("email");
	var DOB = document.getElementById("DOB");
	var password = document.getElementById("pwd1");
	var password2 = document.getElementById("pwd2");
	var gender = document.getElementById("gender");
	var terms = document.getElementById("terms");
	var submit = document.getElementById("submit");
	
	//Enables error messages to be displayed as the user types into an input field
	//keydown event fires when the user presses any key.
	username.addEventListener("keyup", function (){checkUsername(username);});
	email.addEventListener("keyup", function (){checkEmail();});
	DOB.addEventListener("keyup", function (){checkDOB();});
	password.addEventListener("keyup", function (){checkPassword();});
	password2.addEventListener("keyup", function (){confirmPassword();});
	submit.addEventListener("click", function (){return checkGender();});
	submit.addEventListener("click", function (){return checkTerms();});
}// end initialise

//Changes the input field border color to red and displays an error message below the input field 
//to the user if what is supplied by the user is incorrect
//checks username field
function checkUsername () {
	//if field is empty display error message and return false
	if (username.value == "") {
	form.username.style.border = "2px solid red";
	document.getElementById("usernamejsError").innerHTML = "<br/> Please enter a username";
	return false;
	} 
	//if username is less and 5 characters, display error message
	else if (username.value.length < 5) {
	form.username.style.border = "2px solid red";
	document.getElementById('usernamejsError').innerHTML="<br/> Usernames must be at least 5 characters long";
	return false;
	}
	//if username includes special characters (!@#$%^&* etc) except underscores and hyphens
	// display error message and return false 
	else if (/[^a-zA-Z0-9_-]/.test(username.value)) {
	form.username.style.border = "2px solid red";
	document.getElementById('usernamejsError').innerHTML="<br/> Usernames can only include upper and lowercase ".
	"<br/>letters, numbers, underscores (_) or hyphens (-)";
	return false;
	}
	//if no errors, hide error message
	else {
	form.username.style.border = "2px solid #71FF45";
	document.getElementById('usernamejsError').innerHTML="";
	return true;
	}
}// end checkUsername

//checks email field
function checkEmail () {
	if (email.value == "") {
	form.email.style.border = "2px solid red";
	document.getElementById('emailjsError').innerHTML="<br/> Please enter your email address";
	return false;
	}	
	//allows qut email william.nguyen@connect.qut.edu.au in addition to other emails somename@hotmail.com
	else if (!(/[a-zA-Z0-9\.\-]+@[a-zA-Z0-9\-]+\.[a-z]{2,3}(\.[a-z]{2,3})?(\.[a-z]{2})?$/).test(email.value)) { 
	form.email.style.border = "2px solid red";
	document.getElementById('emailjsError').innerHTML="<br/> Please enter a valid email address";
	return false;
	}
	else {
	form.email.style.border = "2px solid #71FF45";
	document.getElementById('emailjsError').innerHTML="";
	return true;
	}
}// end checkEmail

//checks the date of birth matches yyyy-mm-dd-format
function checkDOB() {
	if (DOB.value == "") {
	form.DOB.style.border = "2px solid red";
	document.getElementById('DOBjsError').innerHTML="<br/> Please enter your date of birth";
	return false;
	}
	//http://stackoverflow.com/questions/13194322/php-regex-to-check-date-is-in-yyyy-mm-dd-format
	else if(!(/^[0-9]{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[0-1])$/).test(DOB.value)){ 
	form.DOB.style.border = "2px solid red";
	document.getElementById('DOBjsError').innerHTML="<br/> Please enter a valid date of birth. E.g 21-09-1993";
	return false;
	}
	else {
	form.DOB.style.border = "2px solid #71FF45";
	document.getElementById('DOBjsError').innerHTML="";
	return true;
	}		
}// end checkDOB

//checks password field
function checkPassword () {
	if (pwd1.value === "") {
	form.pwd1.style.border = "2px solid red";
	document.getElementById('pwd1jsError').innerHTML="<br/> Please enter a password";
	return false;
	}
	else if (pwd1.value.length < 6) {
	form.pwd1.style.border = "2px solid red";
	document.getElementById('pwd1jsError').innerHTML="<br/> Passwords must be at least 6 characters long";
	return false;
	}
	else if (!(/^(?=.*[a-z])(?=.*[A-Z])(?=.*\d).+$/.test(pwd1.value))){ 
	form.pwd1.style.border = "2px solid red";
	document.getElementById('pwd1jsError').innerHTML="<br/> Password must include at least one number, and one upper and <br/>lowercase letter and can include symbols";
	return false;
	}
	else {
	form.pwd1.style.border = "2px solid #71FF45";
	document.getElementById('pwd1jsError').innerHTML="";
	return true;
	}
}// end checkPassword

//checks whether passwords match
function confirmPassword () {
	if (pwd1.value !== pwd2.value) {
	form.pwd2.style.border = "2px solid red";
	document.getElementById('pwd2jsError').innerHTML="<br/> Please enter the same Password as above";
	return false;
	}
	else {
	form.pwd2.style.border = "2px solid #71FF45";
	document.getElementById('pwd2jsError').innerHTML="";
	return true;
	}
}//end confirmPassword

//checks if gender radio button is selected
function checkGender() {
	if(!(gender.checked)) {
	//used separate ids for female and male in order to display just one error message
	document.getElementById('Female').innerHTML="<br/>Please select a gender";
	return false;
	} 
}// end checkGender

//checks if the terms checkbox is clicked
function checkTerms () {
	if (!form.terms.checked) {
	document.getElementById('termsjsError').innerHTML="<br/> Please indicate that you accept the Terms and Conditions";
	window.alert("Please fix the following errors");
	return false;
	}
}// checkTerms
<?php
	echo '<!DOCTYPE html>';
	echo '<html>';
		echo '<head>';
			echo '<title>Home</title>';
			echo '<link href="header-footer.css" rel="stylesheet" type="text/css"/>';
			echo'<link rel="stylesheet" href="mystyle.css" />';


		echo '</head>';
		echo '<body>';

			echo '<div id="wrapper">';
				//session_start();

				require '/inc/header-and-menu.inc';
				echo '<div id="out"></div>';

				echo '<div id="searcharea">';
								echo '<label for="search">Art or Suburb name</label>';
								echo '<p>press any key to start search!</p>';
								echo '<input type="search" name="search" id="search" placeholder="name or info" />';
				echo'</div>';
				echo '<div id="update"></div>';
				echo '<div id="pics"></div>';
						//	echo '<script src="jquery.js"></script>';
						echo 	'<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.11.2/jquery.min.js"></script>';
						//echo '<script src="script.js"></script>';
					echo '<fieldset id="Messagebox">';
				//	echo 'Welcome to Brisbane Wi-fi!';
					echo '</fieldset>';

				include '/inc/footer.inc';
			echo '</div>'; //wrapper
		echo '</body>';
	echo '</html>';


//Sensis API request#################################################################################################################################################################################################################
	$json_string = file_get_contents("http://api.sensis.com.au/v1/test/search?&key=efqqs5pf32rsad37vuru9er6&query=art-gallery&location=brisbane/v1/test/search?&key=efqqs5pf32rsad37vuru9er6&query=community-hall&location=brisbane");
	$parsed_json = json_decode($json_string);
	$json = json_encode($parsed_json);

	function fbApi(){
		$json_string = file_get_contents("https://graph.facebook.com/AspireGallery?fields=posts{picture}&access_token=106715286454026|4a8f7aa27529ea64e680e4e8ab7434ca");
		$parsed_json = json_decode($json_string);
		$json = json_encode($parsed_json);
		return $json;
	}

?>



//Storing JSON response from php to js variable for AJAX
<script>

var json = <?php echo $json?>;

var js = json.results;
alert('hello');
//alert(js[0].primaryAddress.suburb);
var fbJson = <?php echo fbApi()?>;
//alert (fbJson.id);

function fbPics(){
	alert (fbJson.id);
	var searchField = $('#search').val();
	var outpic = '<table>';
	var jp = fbJson.posts.data;
		outpic += '<tr>';
		var i=0;
	$.each(jp, function(key, val) {
	  if (i==5){
			outpic += '</tr><tr>';
			i=0;
		}
		outpic += '<td><img src="'+ val.picture +'" alt="n/a" />';
		outpic += '</td>';
		i++;
	});
	outpic += '</tr>';
	outpic +=' </table>';
	$('#pics').html(outpic);

}

function abc(e){
	console.log(e);
	console.log(e.innerHTML);
	$('#search').val(e.innerHTML);
}

var la;
var ln;

//AJAX Instant Search##################################################################
$('#search').keyup(function() {
	search();
});


function search(){

	var searchField = $('#search').val();
	var myExp = new RegExp(searchField, "i");
	//alert('hello');
//	$.getJSON('publicart.json', function(data) {
		//alert('hello');
		var output = '<ul class="searchresults">';
		$.each(js, function(key, val) {
			//alert (data);
			if ((val.name.search(myExp) != -1) ||
			(val.primaryAddress.suburb.search(myExp) != -1)||
			(val.primaryAddress.suburb.search(myExp) != -1)) {
			//function area(){
			ln=Number(val.primaryAddress.longitude);
			//	alert('h');
				la=Number(val.primaryAddress.latitude);
				//	initMap();
		//	}
				output += '<li>';
				output += '<h2 onclick="initMap(la, ln); abc(this); search();fbPics();">'+ val.name+'</h2>';
				//output += '<img src="'+ val.detailsLink +'" alt="'+ val.name +'" />';


				if(val.primaryAddress.suburb!=""){
					output += '<p>'+ "by : "+ val.name +'</p>';}
				output += '<p>'+ "on : "+val.primaryAddress.suburb +'</p>';
				output += '</li>';
			}
		});
		output += '</ul>';
		$('#update').html(output);

}

var map;
 //la  =-25.363;
 //ln = 131.044;
 la = Number(js[0].primaryAddress.latitude);
 //alert(la);
 ln = Number(js[0].primaryAddress.longitude);
function initMap(l,n) {
	if(l==null||n==null){var myLatLng = {lat: la, lng: ln}
	}else {
		var myLatLng = {lat: l, lng: n};

	}

  map = new google.maps.Map(document.getElementById('out'), {
    zoom: 15,
    center: myLatLng
  });
	var marker = new google.maps.Marker({
    position: myLatLng,
    map: map,
    title: 'Hello World!'
  });

}

function map(){
	var myLatLng = {lat: -25.363, lng: 131.044};

	var marker = new google.maps.Marker({
    position: myLatLng,
    map: map,
    title: 'Hello World!'
  });

}
//Get Location
function geoFindMe() {
  var output = document.getElementById("out");

  if (!navigator.geolocation){
    output.innerHTML = "<p>Geolocation not supported by your browser</p>";
    return;
  }

  function success(position) {
    var latitude  = position.coords.latitude;
    var longitude = position.coords.longitude;

    output.innerHTML = '<p>Latitude is ' + latitude + '° <br>Longitude is ' + longitude + '°</p>';

    var img = new Image();
    img.src = "https://maps.googleapis.com/maps/api/staticmap?center=" + latitude + "," + longitude + "&zoom=13&size=300x300&sensor=false";

    output.appendChild(img);

  };
		function error() {
			output.innerHTML = "Unable to retrieve your location";

		};

		output.innerHTML = "<p>Locating…</p>";

		navigator.geolocation.getCurrentPosition(success, error);
}
</script>
<script src="https://maps.googleapis.com/maps/api/js?key=AIzaSyDkB2eh2WaQZGxkSNHMZnnCIVCCRny9P7Q&callback=initMap"async defer></script>

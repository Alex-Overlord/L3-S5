<!doctype html>
<html lang="fr">
<head>
  <meta charset="utf-8" />
	<link rel=stylesheet href=monsite.css type=text/css> 
	<title>MastermindCookies</title>
</head>
<body>

<header>
  <h1>Mastermind avec gestion des Cookies</h1>
</header>

<p>Veuillez saisir successivement des combinaisons de 4 chiffres jusqu'à la victoire !</p>

<form method ="GET" action=''>
  <label for="x"></label>
  <input type='nombre' name='X' id='x' ><br>

	<input type='submit' value='Entrer' name= 'entrer'>
  <input type='submit' value='Recommencer' name= 'recommencer'>
  <input type='submit' value='Charger' name= 'charger'>
	<input type='submit' value='Save' name= 'save'>
</form>

<?php
session_start();

class Nbcache
{
  public $nb1;

  function __construct() { //constructeur
    $this->nb1= random_int(0000, 9999);
    while (strlen($this->nb1) < 4){
      $this->nb1 = "0".$this->nb1;
      }
      echo "<br>(".$this->nb1.")<br>"; //.$nb2.$nb3.$nb4;
  }

  function malPlace($nombre) {
    $sol = 0;
    for ($i=0; $i<4; $i++) { 
      for ($j=0; $j<4; $j++){
        if ($i != $j && substr($this->nb1, $i, 1) == substr($nombre, $j, 1)) {
          $sol++;             
        }
      }
    }       
    return $sol; 
	}
	
  function bienPlace($nombre) {
    $sol = 0;
    for ($i=0; $i<4; $i++) { 
      if (substr($nombre, $i, 1) == substr($this->nb1, $i, 1)) {
        $sol++;
      }           
    }        
    return $sol;
  }

  function affiche() {
    echo "> Code : <br>(".$this->nb1.")<br>";
  }
}
/*
	function fact($i){
    if ($i > 1) { return $i*fact($i-1); }
    else { return 1; }
	}
*/
function afficheEssai($tab){
  foreach ($tab as $value) {
    echo $value ."<br>";
  }
}

if (isset($_GET['entrer'])) {
  if (($_GET['X'] < 10000 and $_GET['X'] > 0000)) {
    echo $_GET['X'];
    echo "<br>"; 
    $res = $soluce->bienPlace($_GET['X']);
    echo "> Correspondance : ".$res ;
  } else {
		echo $_GET['X']." est incorrect ";   
	}
}



if (isset($_GET['save']) or isset($_GET['charger'])) {
	if (isset($_GET['save'])) {
		$soluce = unserialize($_SESSION['historique']);
		setcookie('sauvegarde', serialize($soluce), time()+9999);
		$soluce->affiche();
	}
	if (isset($_COOKIE['sauvegarde']) and isset($_GET['charger'])) {
		$soluce = unserialize($_COOKIE['sauvegarde']);
		$soluce->affiche();
		echo "<br>Chargement partie<br>";
		$_SESSION['historique'] = serialize($soluce);
	}
} else if (isset($_GET['recommencer']) || !(isset($_SESSION['historique']))) {
  $soluce = new NbCache();
  $hist = $soluce; 
  $_SESSION['historique'] = serialize($hist); 
	//echo isset($soluce)." <br> reset ou premiere connection <br> ";
	echo " <br> reset ou premiere connection <br> ";
} else {
  $soluce = unserialize($_SESSION['historique']);  
  $soluce->affiche();
}

?>
</body>
<footer>
</footer>
</html>
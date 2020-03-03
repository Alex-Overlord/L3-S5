<!DOCTYPE html>
<html lang="fr">
<head>
  <meta charset="UTF-8">
  <link rel="stylesheet" href="infocom.css">
  <title>Mastermind</title>
</head>
<body>

<header>
  <h1>Mastermind</h1>
  <p>Veuillez saisir successivement des combinaisons de 4 chiffres jusqu'à la victoire !</p>
</header>
  
<?php
  class Mastermind {
    public $coups = array(); // les essais
    public $code; // le code (nombre de 0 à 9999)
    protected $A; // chiffre des milliers
    protected $B; // chiffre des centaines
    protected $C; // chiffre des dizaines
    protected $D; // chiffre des unités
    public $good; // nb de chiffre bien placé
    public $bad; // nb de chiffre mal placés
    public $num; // numéro de l'essai

    public function __construct() {
      $code = rand(0, 9999);
      $A = $code / 1000;
      $B = ($code / 100) % 10;
      $C = ($code / 10) % 100;
      $D = $code % 1000;
      echo $code;
    }

    public function getA() { return $this->$A; }
    public function setA($A) { $this->A = $A; }
    public function getB() { return $this->$B; }
    public function setB($B) { $this->B = $B; }
    public function getC() { return $this->$C; }
    public function setC($C) { $this->C = $C; }
    public function getD() { return $this->$D; }
    public function setD($D) { $this->D = $D; }

    //public function
  }
  $game = new Mastermind;
  $game->__construct();
  //$game->getA();
  //$game->getB();
  //$game->getC();
  //$game->getD();
?>

<!-- <input  -->


</body>
</html>
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
  interface iMastermind {
    public function __construct($taille = 4);
    public function test($code);
    //public function getEssai();
    //public function getTaille();
  }

  class Mastermind implements iMastermind {
    protected $code = "";
    protected $essai = array();

    public function __construct($taille = 4) {
      for ($i=0; $i<taille; $i++) {
        $c = rand(0,9);
        $this->code.="$c";
      }
    }

    public function test($essai) {
      $code = $essai;
      if (!$this->valide($code)) {
        return false;
      }
      $res = array("bon" => 0, "mal" => 0);
      $code2 = $this->code;
      for ($i=0; $i<strlen($code); $i++) {
        if ($code[$i]==$code3[$i]) {
          $res["bon"]++;
          $code[$i] = '_';
          $code2[$i] = '_';
        }
      }
      for ($i=0; $i<strlen($code); $i++) {
        if ($code[$i]!='-') {
          $pos = strpos($code2, $code[$i]);
          if (!($pos===false)) {
            $res['mal']++;
            $code2[$i] = '_';
          }
        }
      }
      $this->essai[$essai] = $res;
      return $res;
    }
  }
?>

<form method="post"> 
<p>Veuillez saisir successivement des combinaisons de

4 chiffres jusqu'à la victoire !
</p>
<table>
 <tbody><tr>
  <th align="left" valign="middle">Numéro</th>
  <th align="left" valign="middle">Proposition</th>
  <th align="left" valign="middle">Bien placé(s)</th>
  <th align="left" valign="middle">Mal placé(s)</th>
  </tr>
  <tr><td>1</td><td>
    <input type="text" name="prop" autofocus="" size="4" <="" td="">
  </td><td></td><td></td></tr>
    </tbody></table>
    <input type="submit" value="OK">
    <input type="submit" name="nouveau" value="Nouvelle Partie">
   </form>

</body>
</html>
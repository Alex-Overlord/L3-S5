<!DOCTYPE html>
<html>
<body>

<?php
  function fact($x) {
    if ($x <= 0) {
      return 1;
    }
    else {
      return $x * fact($x-1);
    }
  }
?>

<form method="get">
  <label for="x">Enter a number :</label>
  <input type="number" name="x" id="x">
  <input type="submit" value="Calculer Factoriel" name="fact">
</form>

<?php
  if (isset($_GET["x"])) {
    echo "Resultat de ", $_GET["x"], "! = ", fact($_GET["x"]);  
  }
?>

</body>
</html> 
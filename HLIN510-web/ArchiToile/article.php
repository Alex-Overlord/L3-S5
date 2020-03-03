<!DOCTYPE html>
<html>
<body>

<?php
  $article=array("marteau"=>10, "tenaille"=>5, 'vis'=>5.2,
    "clou"=>5.8, "tournevis"=>7, "ciseau"=>4, "toile"=>3);
  function total() {
    $som = 0;
    if (isset($_GET["marteau"])) { $som += $article["marteau"] * $_GET["marteau"]; }
    if (isset($_GET["tenaille"])) { $som += $article["tenaille"] * $_GET["tenaille"]; }
    if (isset($_GET["vis"])) { $som += $article["vis"] * $_GET["clou"]; }
    if (isset($_GET["tournevis"])) { $som += $article["tournevis"] * $_GET["tournevis"]; }
    if (isset($_GET["ciseau"])) { $som += $article["ciseau"] * $_GET["ciseau"]; }
    if (isset($_GET["toile"])) { $som += $article["toile"] * $_GET["toile"]; }
    return $som;
  }
?>

<form method="get">
  <input type="number" name="marteau">
  <label for="marteau">Marteau</label> <br>

  <input type="number" name="tenaille">
  <label for="tenaille">Tenaille</label> <br>

  <input type="number" name="vis">
  <label for="vis">Vis</label> <br>

  <input type="number" name="clou">
  <label for="clou">Clou</label> <br>

  <input type="number" name="tournevis">
  <label for="tournevis">Tournevis</label> <br>

  <input type="number" name="ciseau">
  <label for="ciseau">Ciseau</label> <br>

  <input type="number" name="toile">
  <label for="toile">Toile émeri</label> <br>

  <input type="submit" value="Calculer le Total" name="fact">
</form>

<?php
  echo "Total : ", total();  
?>

</body>
</html> 
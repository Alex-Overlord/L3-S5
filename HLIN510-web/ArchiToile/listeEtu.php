<!DOCTYPE html>
<html lang="fr">
<head>
  <meta charset="UTF-8">
  <link rel="stylesheet" href="infocom.css">
  <title>Liste des noms d'étudiants</title>
</head>
<body>

<?php
	$user="e20170006075";
	$pass="230998";
	$i=1;
	try {
		$dbh = new PDO('mysql:host=mysql.etu.umontpellier.fr;dbname=e20170006075;charset=utf8', $user, $pass);
		foreach ($dbh->query('SELECT * FROM Etudiant;') as $row) {
			echo $i." ".$row['nom']." ".$row['prenom']."<br/>";
			$i++;
		}
		$dbh = null;
	} catch (PDOException $e) {
		print "Erreur ! :".$e->getMessage()."<br/>";
		die();
	}
?>

</body>
</html>
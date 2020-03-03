<!DOCTYPE html>
<html lang="fr">
<head>
  <meta charset="UTF-8">
  <link rel="stylesheet" href="infocom.css">
  <title>Liste des noms d'étudiants</title>
</head>
<body>
<table>
<tr>
    <th>PRENOM</th>
    <th>NOM</th>
    <th>STATUT</th>
    <th>EMAIL</th>
    <th>GROUPE</th>
    <th>OPT</th>
    <th>NUMERO STAGE A</th>
</tr>

<?php
	$user="e20170006075";
	$pass="230998";
	$i=1;
	$numTmp=1;
	try {
		$dbh = new PDO('mysql:host=mysql.etu.umontpellier.fr;dbname=e20170006075;charset=utf8', $user, $pass);
		foreach ($dbh->query('SELECT E.prenom, E.nom, E.statut, E.email, E.groupe, E.opt, E.numStageA FROM etudiant E, stagea S WHERE E.numStageA = S.numStageA') as $row) {

			//if ($numTmp < $row['numStageA']) {
			//	print "<hr/>";
			//}
			//echo $i." ".$row['prenom']." ".$row['nom']." ".$row['numStageA']."<br/>";
?>
			<tr>
                <td id="prenom"><?php echo $row['prenom']; ?></td>
                <td id="nom"><?php echo $row['nom']; ?></td>
                <td id="statut"><?php echo $row['statut']; ?></td>
                <td id="email"><?php echo $row['email']; ?></td>
                <td id="groupe"><?php echo $row['groupe']; ?></td>
                <td id="opt"><?php echo $row['opt']; ?></td>
                <td id="numStageA"><?php echo $row['numStageA']; ?></td>
            </tr>
<?php
			$i++;
			//$numTmp = $row['numStageA'];
		}
		$dbh = null;
	} catch (PDOException $e) {
		print "Erreur ! :".$e->getMessage()."<br/>";
		die();
	}
?>
</table>

</body>
</html>
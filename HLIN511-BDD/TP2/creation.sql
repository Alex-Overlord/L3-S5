DROP TABLE Emprunt; 
DROP TABLE Caracterise; 
DROP TABLE Mot_clef; 
DROP TABLE Exemplaire; 
DROP TABLE Abonne; 
DROP TABLE Livre; 
DROP TABLE Auteur;

CREATE TABLE Livre (
	isbn VARCHAR(20),
	titre VARCHAR(50) CONSTRAINT titre_not_null NOT NULL, 
	siecle NUMERIC(2,0) CHECK (siecle BETWEEN 0 and 21),
	categorie VARCHAR(10)
);

CREATE TABLE Abonne (
	ab_num NUMERIC(6,0),  
	nom VARCHAR(30) CONSTRAINT ab_nom NOT NULL, 
	prenom VARCHAR(30), 
	ville VARCHAR(30), 
	age NUMERIC(3,0),
 	tarif NUMERIC(5,0),
 	reduc NUMERIC(3,0),
	CONSTRAINT dom_age CHECK (age BETWEEN 0 AND 120)
);

CREATE TABLE Exemplaire (
	numero NUMERIC(4,0), 
	date_achat DATE, 
	prix NUMERIC(5,2), 
	code_pret VARCHAR(12),
	etat VARCHAR(15) CHECK (etat IN ('BON','ABIME','EN_REPARATION')), 
	isbn VARCHAR(20),
	CONSTRAINT dom_code_pret CHECK (code_pret IN ('EXCLU','EMPRUNTABLE','CONSULTABLE')) 
);

CREATE TABLE Mot_clef (
	mot VARCHAR(20)
);

CREATE TABLE Caracterise (
	isbn VARCHAR(20), 
	mot VARCHAR(20)
);

CREATE TABLE Emprunt (
	ab_num NUMERIC (6,0),
	ex_num NUMERIC (4,0),
	d_emprunt DATE, 
	d_retour DATE, 
	d_ret_real DATE, 
	nb_relance NUMERIC(1,0) CHECK (nb_relance IN (1,2,3))
);
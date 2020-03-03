-- Q1)
-- Q2)

-- Livre
ALTER TABLE Livre ADD CONSTRAINT livre_pk PRIMARY KEY (isbn);

-- Abonne
ALTER TABLE Abonne ADD CONSTRAINT abonne_pk PRIMARY KEY (ab_num);
ALTER TABLE Abonne ADD date_nai DATE;
ALTER TABLE Abonne ADD ab_type VARCHAR(30);
ALTER TABLE Abonne ADD ab_cat VARCHAR(30);
ALTER TABLE Abonne ADD CONSTRAINT dom_ab_type CHECK (ab_type IN ('REGULIER','OCCASIONNEL','A PROBLEME','EXCLU'));
ALTER TABLE Abonne ADD CONSTRAINT dom_ab_cat CHECK (ab_cat IN ('ADULTE','ENFANT'));

INSERT INTO Abonne VALUES (1,'CANTON CONDES','ALEXANDRE','MONTPELLIER',26,100,50,'26-02-1993','REGULIER','ADULTE');
INSERT INTO Abonne VALUES (2,'LAMOUCHI','AMBRE','MONTPELLIER',21,100,50,'23-09-1998','OCCASIONNEL','ADULTE');
INSERT INTO Abonne VALUES (3,'BARDIN','MELVIN','MONTPELLIER',21,100,25,'26-03-1997','REGULIER','ADULTE');

-- INSERT INTO ABONNE VALUES (901001,'LEVEQUE','PIERRE','MONTPELLIER',27121971,40,500,NULL,'15-02-1979'); 
-- INSERT INTO ABONNE VALUES (902043,'DUPONT','MARIE','MONTPELLIER',31101975,20,200,20,'15-02-1999'); 
-- INSERT INTO ABONNE VALUES (902075,'RENARD','ALBERT','MONTPELLIER',10031976,18,200,NULL,'15-02-2001'); 
-- INSERT INTO ABONNE VALUES (911007,'MARTIN','LOIC','BEZIER',20061984,35,500,20,'15-02-1986'); 
-- INSERT INTO ABONNE VALUES (911021,'DUPONT','ANTOINE','MONTPELLIER',11071985,38,200,NULL,'15-02-1981'); 
-- INSERT INTO ABONNE VALUES (911022,'DUPONT','SYLVIE','MONTPELLIER',26011988,35,300,NULL,'15-02-1984'); 
-- INSERT INTO ABONNE VALUES (911023,'DUPONT','JEAN','MONTPELLIER',18051988,22,100,20,'15-02-1997'); 
-- INSERT INTO ABONNE VALUES (922011,'MEUNIER','LUC','MONTPELLIER',06121991,14,90,NULL,'15-02-2005'); 
-- INSERT INTO ABONNE VALUES (921102,'LUCAS','PAUL','MONTPELLIER',16121992,48,300,20,'15-02-1981'); 
-- INSERT INTO ABONNE VALUES (922143,'REVEST','ANNIE','MONTPELLIER',21101998,12,100,NULL,'15-02-2007'); 
-- INSERT INTO ABONNE VALUES (932010,'ANTON','JEANNE','MONTPELLIER',23102000,10,100,NULL,'15-02-2009'); 

-- Exemplaire
ALTER TABLE Exemplaire ADD CONSTRAINT exemplaire_pk PRIMARY KEY (numero);
ALTER TABLE Exemplaire ADD CONSTRAINT exemplaire_fk FOREIGN KEY (isbn) REFERENCES Livre(isbn);
ALTER TABLE Exemplaire ADD etat VARCHAR(15) CHECK (etat IN ('BON','ABIME','EN_REPARATION'));

-- Mot_clef
ALTER TABLE Mot_clef ADD CONSTRAINT mot_pk PRIMARY KEY (mot);
ALTER TABLE Mot_clef ADD mot_pere VARCHAR(20);
ALTER TABLE Mot_clef ADD CONSTRAINT mot_fk FOREIGN KEY (mot_pere) REFERENCES Mot_clef(mot); -- ne marche pas

-- Q7)
CREATE TABLE Auteur (
  aut_id NUMERIC(6),
  aut_nom VARCHAR(30),
  aut_prenom VARCHAR(30),
  aut_pays VARCHAR(30),
  CONSTRAINT pk_aut_id PRIMARY KEY (aut_id)
);

ALTER TABLE Livre ADD livre_aut_id NUMERIC(6);
ALTER TABLE Livre ADD CONSTRAINT fk_livre_aut FOREIGN KEY (livre_aut_id) REFERENCES Auteur(aut_id);
ALTER TABLE Livre DROP CONSTRAINT titre_not_null;

INSERT INTO Auteur VALUES (101,'DUMAS','ALEXANDRE','FRANCAISE');
INSERT INTO Auteur VALUES (102,'SARTRE','JEAN-PAUL','FRANCAISE');
INSERT INTO Auteur VALUES (103,'GENEY','JEAN','FRANCAISE');
INSERT INTO Auteur VALUES (104,'VALLES','JULES','FRANCAISE');
INSERT INTO Auteur VALUES (105,'VILLON','FRANCOIS','FRANCAISE');
INSERT INTO Auteur VALUES (106,'ECO','UMBERTO','ITALIENNE');
INSERT INTO Auteur VALUES (107,'GARY','ROMAIN','FRANCAISE');
INSERT INTO Auteur VALUES (108,'ROCHEFORT','CHRISTIANE','FRANCAISE');
INSERT INTO Auteur VALUES (109,'STEINBECK','JOHN','AMERICAIN');
INSERT INTO Auteur VALUES (110,'HOFSTADTER','DOUGLAS','ALLEMAND');
INSERT INTO Auteur VALUES (111,'BOUZEGHOUB','MOKRANE','TUNISIENNE');
INSERT INTO Auteur VALUES (112,'GARDARIN','GEORGES','FRANCAISE');
INSERT INTO Auteur VALUES (113,'VALDURIEZ','PATRICK','FRANCAISE');
INSERT INTO Auteur VALUES (114,'ULLMAN','JEFFREY','AMERICAINE');
INSERT INTO Auteur VALUES (115,'DELOBEL','CLAUDE','FRANCAISE');
INSERT INTO Auteur VALUES (116,'DATE','JC','AMERICAINE');
INSERT INTO Auteur VALUES (117,'GELENBE','EROL','INDIENNE');
INSERT INTO Auteur VALUES (118,'FLORY','ANDRE','FRANCAISE');

CREATE TABLE Ecrit (
  ecr_aut_id NUMERIC(6),
  ecr_livre_isbn VARCHAR(20),
  CONSTRAINT fk_ecr_aut FOREIGN KEY (ecr_aut_id) REFERENCES Auteur(aut_id),
  CONSTRAINT fk_ecr_livre FOREIGN KEY (ecr_livre_isbn) REFERENCES Livre(isbn),
  CONSTRAINT pk_ecr PRIMARY KEY (ecr_aut_id, ecr_livre_isbn)
);

INSERT INTO Ecrit VALUES (102,'1_104_1050_2');
INSERT INTO Ecrit VALUES (103,'0_15_270500_3');
INSERT INTO Ecrit VALUES (104,'0_85_4107_3');
INSERT INTO Ecrit VALUES (105,'0_112_3785_5');
INSERT INTO Ecrit VALUES (116,'0_201_14439_5');
INSERT INTO Ecrit VALUES (112,'0_12_27550_2');
INSERT INTO Ecrit VALUES (117,'0_12_27550_2');
INSERT INTO Ecrit VALUES (111,'0_8_7707_2');
INSERT INTO Ecrit VALUES (118,'0_8_7707_2');
INSERT INTO Ecrit VALUES (106,'1_22_1721_3');
INSERT INTO Ecrit VALUES (107,'3_505_13700_5');
INSERT INTO Ecrit VALUES (108,'0_18_47892_2');
INSERT INTO Ecrit VALUES (109,'9_782070_36');
INSERT INTO Ecrit VALUES (110,'2_7296_0040');
INSERT INTO Ecrit VALUES (111,'0_26_28079_6');
INSERT INTO Ecrit VALUES (112,'0_26_28079_6');
INSERT INTO Ecrit VALUES (113,'0_26_28079_6');

-- Q15
CREATE VIEW AbonneMtp (ab_num, nom, prenom, ville) AS 
  SELECT ab_num, nom, prenom, ville 
  FROM Abonne 
  WHERE ville = 'MONTPELLIER'
  WITH CHECK OPTION;

INSERT INTO AbonneMtp VALUES (4,'MAEL','BONNEAU','MONTPELLIER');

-- Q17
CREATE VIEW EtatExemplaire (numero, date_achat, prix, code_pret, etat, isbn) AS
  SELECT numero, date_achat, prix, code_pret, etat, isbn 
  FROM Exemplaire 
  WHERE etat IN ('BON','ABIME','EN_REPARATION')
  AND code_pret IN ('EXCLU','EMPRUNTABLE','CONSULTABLE')
  WITH CHECK OPTION;

-- INSERT INTO EtatExemplaire VALUES (1013, '10-04-2006',55,'EMPRUNTABLE','TEST','0_18_47892_2'); 
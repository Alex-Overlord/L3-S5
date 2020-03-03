prompt --**********************************--;
prompt -- Q1 -- ;
prompt --**********************************--;

-- alter table abonne
-- drop constraint;

alter table abonne
add date_naissance DATE;

ALTER TABLE Abonne
ADD TYPE_AB varchar(7);

Alter table abonne
add constraint dom_type
check(TYPE_AB in ('adulte','enfant'));

/* 
tester si empeche les autres input, si oui, rajouter notnull
*/

-- A priori les inputs sont exclusifs

alter table abonne
add cat_ab varchar(12);

alter table abonne
add constraint dom_cat
check (cat_ab in ('REGULIER', 'OCCASIONNEL', 'A PROBLEME', 'EXCLU'));

/*select *
from abonne
where num_ab='932010';

-- INSERT INTO ABONNE VALUES (932010,'ANTON','JEANNE','MONTPELLIER',10,100,'10/10/1961',NULL,NULL); 

select *
from abonne
where num_ab='932010';
*/

desc abonne;

prompt --**********************************--;
prompt -- Q2 -- ;
prompt --**********************************--;

alter table abonne
modify tarif number(5);

desc abonne;

prompt --**********************************--;
prompt -- Q3 -- ;
prompt --**********************************--;

ALTER TABLE MOT_CLEF
ADD MOT_PERE VARCHAR(20);

UPDATE MOT_CLEF SET MOT_PERE = 'ROOT' WHERE MOT='MEDECINE';
UPDATE MOT_CLEF SET MOT_PERE = 'ROOT' WHERE MOT='LITTERATURE';
UPDATE MOT_CLEF SET MOT_PERE = 'ROOT' WHERE MOT='SCIENCES';
UPDATE MOT_CLEF SET MOT_PERE = 'SCIENCES' WHERE MOT='INFORMATIQUE';
UPDATE MOT_CLEF SET MOT_PERE = 'INFORMATIQUE' WHERE MOT='PROGRAMMATION';
UPDATE MOT_CLEF SET MOT_PERE = 'INFORMATIQUE' WHERE MOT='BASE DE DONNEES';
UPDATE MOT_CLEF SET MOT_PERE = 'BASE DE DONNEES' WHERE MOT='MODELE RELATIONNEL';
UPDATE MOT_CLEF SET MOT_PERE = 'BASE DE DONNEES' WHERE MOT='MODELES ORIENTES OBJETS';

DESC MOT_CLEF;

prompt -- Arborescence/Thesaurus crée ;

prompt --**********************************--;
prompt -- Q4 -- ;
prompt --**********************************--;

DROP TABLE AUTEUR;

CREATE TABLE AUTEUR (
       ID NUMERIC(6) PRIMARY KEY,
       NOM VARCHAR(50),
       PRENOM VARCHAR(50),
       NATIONALITE VARCHAR(50)
       );

prompt -- AUTEUR créé ;

desc AUTEUR;

DROP TABLE ECRIT

CREATE TABLE ECRIT(
       IDA NUMERIC(6),
       ISBN VARCHAR(20),
       CONSTRAINT pk_ecrit PRIMARY KEY (IDA, ISBN),
       CONSTRAINT fk_ida FOREIGN KEY(IDA) references AUTEUR(ID),
       CONSTRAINT fk_isbn FOREIGN KEY(ISBN) references LIVRE(ISBN)
       );

prompt -- ECRIT créé ;


DESC ECRIT;

prompt --**********************************--;
prompt -- Q5 -- ;
prompt --**********************************--;


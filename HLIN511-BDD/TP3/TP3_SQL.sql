
Q1)

CREATE TABLE AB_NB (
	NB NUMERIC(3),
	NUMERO NUMERIC(6)
);

SET SERVEROUTPUT ON 
DECLARE
	nbre NUMBER(3);
	num ABONNE.NUM_AB%type;
BEGIN
	num :=&numabonne;
	select count(*) into nbre
	from Emprunt where num_ab = num;
	dbms_output.put_line('nbre emprunts' || nbre);
	---exception when no_data_found then dbms_output.put_line('erreur');---
	IF nbre=0 THEN dbms_output.put_line('erreur');
	ELSE 
	insert into AB_NB values (nbre,num);
	END IF;
END;
/


Q2)

CREATE or replace PROCEDURE nb_pret (num in number , nb out number)
is 
	BEGIN
		select count(*) into nb 
		from Emprunt where num_ab = num;

	END;
/

Q3)

SET SERVEROUTPUT ON 
DECLARE
	nb NUMBER(3);
	num ABONNE.NUM_AB%type;
BEGIN
	num :=&numabonne;
	nb_pret(num,nb);
	dbms_output.put_line('nbre emprunts ' || nb);
	---exception when no_data_found then dbms_output.put_line('erreur');---
	IF nb=0 THEN dbms_output.put_line('erreur');
	ELSE 
	insert into AB_NB values (nb,num);
	END IF;
END;
/

Q4)
SET SERVEROUTPUT ON
DECLARE
	cat LIVRE.categorie%type;
	CURSOR les_ab IS  select num_ab from ABONNE;
	num ABONNE.NUM_AB%type;
	nb NUMBER(3);
BEGIN
	OPEN les_ab;
	LOOP
		FETCH les_ab INTO num;
		select count(*), categorie into nb, cat 
		from Emprunt natural join exemplaire natural join livre where num_ab=num group by categorie;
		dbms_output.put_line('L Abonne '  || num || ' a emprunte :' || nb || ' Livre');
	EXIT WHEN les_ab%NOTFOUND;
	END LOOP;
END;
/




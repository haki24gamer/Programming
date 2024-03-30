--Filiere
INSERT INTO Filiere VALUES (1,'informatique');
INSERT INTO Filiere VALUES (2,'comptabilite');
INSERT INTO Filiere VALUES (3,'logistique');

--Etudiant
INSERT INTO Etudiant VALUES (1,'Houmed abdi farah','abdi','Masculin','ali120@yahoo.fr','quartier4 avenue13', 1);
INSERT INTO Etudiant VALUES (3,'gouled farah hassan','gedi','Masculin','gouled@yahoo.fr','cite wadajir 1', 2);

--Enseignant
INSERT INTO Enseignant VALUES (1,'Mohamed Yonis Guedi', 'Masculin', 'med120@yahoo.fr','cite wadajir 1',77113456,'Docteur','kad125');
INSERT INTO Enseignant VALUES (2,'Samatar Farah Hassan', 'Masculin', 'sam67@yahoo.fr','hayableh',77016545,'Master','sam2024');
INSERT INTO Enseignant VALUES (3,'Nima Djama ahmed', 'Feminin', 'nimaprincesse@gmail.com','quartier 7',77566434,'Master','Nim98');

--Module
INSERT INTO Module VALUES (456,'Technologie Web', 5, 56, 1);
INSERT INTO Module VALUES (500,'Programmation Oriente Objet', 5, 56, 2);
INSERT INTO Module VALUES (856,'Introduction aux Reseaux', 6, 70, 1);
INSERT INTO Module VALUES (900,'Anglais', 3, 30, 3);

--Note
INSERT INTO Note VALUES (6,5,8,2,'2019-2020',1,900);
INSERT INTO Note VALUES (7,4,9,2,'2019-2020',3,900);
INSERT INTO Note VALUES (29,15,4,4,'2021-2022',3,456);
INSERT INTO Note VALUES (5,11,9,4,'2019-2020',3,456);

select * from etudiant,filiere where etudiant.num_filiere=filiere.num_filiere and filiere.nom_filiere='Informatique';

DELETE FROM etudiant WHERE numero_etudiant = 2;

UPDATE etudiant SET nom_etudiant='houmed abdi farah' where numero_etudiant=1;
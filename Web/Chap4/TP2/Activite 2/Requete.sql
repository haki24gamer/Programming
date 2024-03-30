
delete from Etudiant WHERE numero_etudiant='1';

UPDATE Etudiant
    SET nom_etudiant='houmed abdi farah'
    WHERE numero_etudiant=1;

SELECT * FROM Etudiant;

SELECT Etudiant.* FROM Etudiant,Filiere WHERE Etudiant.num_filiere=Filiere.num_filiere AND nom_filiere='informatique';

SELECT Etudiant.* FROM Etudiant,Filiere,
    WHERE Etudiant.num_filiere=Filiere.num_filiere
    AND nom_filiere='informatique'
    AND semestre/2=2;

SELECT * FROM Module,Enseignant
    WHERE MODULE.numero_enseignant=Enseignant.numero_enseignant
    AND nom_enseignant='Ali Abdi Farah';

SELECT controle_continu, controle_finale
    FROM Note, Etudiant
    WHERE Note.numero_etudiant=Etudiant.numero_etudiant
    AND numero_etudiant=5478;

SELECT controle_continu, controle_finale
    FROM Note, Etudiant, MODULE
    WHERE Note.numero_etudiant=Etudiant.numero_etudiant
    AND numero_etudiant=5478
    AND nom_module='Technologie Web';

SELECT Note.numero_etudiant,nom_etudiant,AVG(controle_continu) AS MoyCC,AVG(controle_finale) AS MoyCF
    FROM Note,Etudiant
    WHERE Note.numero_etudiant=Etudiant.numero_etudiant
    GROUP BY numero_etudiant;
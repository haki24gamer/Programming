--- 1. Modifier les noms des auteurs avec plus de 3 ouvrages par la valeur de votre choix
UPDATE auteur AS a
SET NomAut = 'Chef Auteur'
WHERE NumAut IN (
  SELECT e.NumAut
  FROM ecrire e
  GROUP BY e.NumAut
  HAVING COUNT(*) > 3
);

-- 2. Modifier la ref des ouvrages avec moins de 4 exemplaires de bons états par "ouvrage avec - de 4 exemplaires" prenant en compte aussi les ouvrage avec 0 exemplaire en bon état
UPDATE ouvrage AS o
SET refouvrage = 'ouvrage avec - de 4 exemplaires'
WHERE o.Nidentifiant IN (
  SELECT ex.Nidentifiant
  FROM exemplaire ex
  WHERE ex.etat LIKE 'bonne'
  GROUP BY ex.Nidentifiant
  HAVING COUNT(*) < 4
);

-- 3. Modifier l'état des exemplaires acquis en 2020 par mauvais
UPDATE exemplaire
SET etat = 'mauvais'
WHERE YEAR(dateAcquisition) = 2020;

-- 4. Supprimer les auteurs n'ayant écrit aucun ouvrage
DELETE FROM auteur
WHERE NumAut NOT IN (
  SELECT e.NumAut
  FROM ecrire e
);

-- 5. Supprimer tous les ouvrages n'ayant aucun exemplaire en bon état
DELETE FROM ouvrage
WHERE Nidentifiant NOT IN (
  SELECT ex.Nidentifiant
  FROM exemplaire ex
  WHERE ex.etat LIKE 'bonne'
);


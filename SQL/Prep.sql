//1. Creer les utilisateurs
create user houssein identified by password1;
create user Amire identified by password2;

//2. Autoriser aux utilisateurs le droit de se connecter a la base vente
grant connect to houssein, Amire;

//3. Accorder le privileges de creer des tables , des vues a ces utilisateurs
grant create table, create view to houssein;

//4. Autoriser Houssein a lancer des ordres sql select sur la table magasin
grant select on magasin to Houssein;

//5. Autoriser Houssein a lancer de ordres sql select sur la table magasin
grant select on magasin to houssein;

//6. Autoriser Amire a lancer des ordres sql select sur la table articles, mais aussi a transmettre a tous les users
grant select on article to Amire with grant option;

//7. Autoriser Amire a lancer des ordres sql select, insert, delete sur la table Frs
grant select, insert, delete on Frs to Amire;

//8. Autorise tous les utilisateurs présents et à venir à lancer des ordres SQL SELECTet UPDATE sur la table Vente.
grant select, update on Vente to public;

//9. Modifier le nom de l'utilisateur Houssein par Hassan.
alter user houssein rename to Houssein;

//10. Ce qui autorise Hassan à lancer sur la table Vente, les mêmes ordres SQL, que ceux autorisés à Isra (SELECT, INSERT, DELETE). On parle alors d'héritage de droits c'est-à- dire que l'utilisateur doté de ces droits peut à nouveau les céder à un ou plusieurs autres utilisateurs.
Grant select, insert, delete on vente to Hassan;

//11. Autoriser Israà lancer des ordres UPDATE sur la table Vente.
grant update on Vente to Hassan;

//12. Modifier le mot de passe de l'utilisateur Amira par 12infos.
alter user Amire identified by L2Info;

//13. Supprimer le privilège de sélection de la table Vente attribué à Hassan.
revoke select on vente from Hassan;

//14.  Supprime les privilèges d'insertion et de suppression de la table Vente attribuées à Rachid et Hassan dans I'exemple 2, mais pas celui de mise à jour (UPDATE).
revoke insert, delete on Vente from Amire;

//15. Supprime la possibilité pour Amira de transmettre le privilège de sélection sur la table Vente.
revoke grant option for select on Vente from Amire;

//16. Retirer tous les privilėges à I'utilisateur Hassan.
revoke all privileges from houssein;

//17. Supprimer I'utilisateur Amira.
drop user Hassan;


// Montre tout les utilisateurs
select username from all_users;






//other

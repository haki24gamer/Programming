
/* TP5 */
//Creation
create table magasin (
    num_m varchar2(30),
    loc varchar2(30),
    constraint pk_num_m primary key (num_m)
);

create table frs(
    num_f varchar2(30),
    nom varchar2(30),
    ville varchar2(30),
    constraint pk_num_f primary key (num_f)
);


create table client(
    num_c varchar2(30),
    nom varchar2(30),
    pays varchar2(30),
    ville varchar2(30),
    constraint pk_num_c primary key (num_c)
);

create table article(
    num_a varchar2(30),
    des varchar2(30),
    poids number(20),
    couleur varchar2(30),
    prix_achat float(10),
    num_f varchar2(30),
    constraint pk_num_a primary key (num_a),
    constraint fk_num_f foreign key (num_f) references frs(num_f)
);

create table vente(
    num_c varchar2(30),
    num_a varchar2(30),
    num_m varchar2(30),
    qte float(10),
    prix_vente float(10),
    dat date,
    constraint fk_num_c foreign key (num_c) references client(num_c),
    constraint fk_num_a foreign key (num_a) references article(num_a),
    constraint fk_num_m foreign key (num_m) references magasin(num_m)
);


/* TP6 */
//Insertion
insert into magasin values ('M1','Chnenni');
insert into magasin values ('M2','Ain Slam');
insert into magasin values ('M3','Elmanzel');

insert into frs values ('F1','Tounsi Ali','Sousse');
insert into frs values ('F2','Sfaxi Hedi','Sousse');
insert into frs values ('F3','Gabsi Amin','Gabes');

insert into client values ('C1','Jerbi Slim','Tunisie','Tunisie');
insert into client values ('C2','Ayed Sami','Tunisie','Gabes');
insert into client (num_c,pays,ville) values ('c3','France','Paris');
update client set num_c = 'C3' where num_c = 'c3';

insert into vente values ('C1','A2','M1',20.250,330,to_date('12-10-2010','dd-mm-yyyy'));
insert into vente values ('C2','A4','M1',100,300,to_date('4-2-2008','dd-mm-yyyy'));
insert into vente values ('C3','A2','M3',500,380.5,to_date('25-2-2009','dd-mm-yyyy'));
insert into vente values ('C1','A3','M2',120.2,195.5,to_date('15-6-2011','dd-mm-yyyy'));
insert into vente values ('C2','A1','M3',30,150.750,to_date('30-8-2012','dd-mm-yyyy'));
insert into vente values ('C1','A5','M1',750.5,210,to_date('14-12-2011','dd-mm-yyyy'));
insert into vente values ('C1','A1','M1',600.7,200,to_date('23-3-2007','dd-mm-yyyy'));
insert into vente values ('C3','A4','M3',300,430.5,to_date('17-6-2009','dd-mm-yyyy'));
insert into vente values ('C1','A1','M2',20,220,to_date('22-3-2008','dd-mm-yyyy'));
insert into vente values ('C3','A5','M2',100,130.3,to_date('3-10-2007','dd-mm-yyyy'));


//Modifier les contenus
update client set nom='Med Ghribi' where num_c='C3';
update article set prix_achat=20 where num_A='A5';
update article set poids=10;
create table frs_sousse as select * from frs where ville='Sousse';

/* TP7 */
//1
select nom, ville from frs;
select distinct(ville) from frs;
select des, poids from article;
select * from client where num_c='C1';
select poids from article where num_a='A3';
//6
select num_a, des from article where couleur='Vert';
select des from article  where couleur='Vert' and prix_achat>500;
select num_c, nom from client where ville='Gabes' and nom like 'A%';
select * from article where des like '%er' or couleur='Vert';
select * from article where poids between 200 and 300;
//11
select * from frs where ville='Tunis';
select distinct(loc) from magasin;
select * from vente order by dat asc;
select nom, pays, ville from client order by nom asc;
select * from magasin where loc like 'E%';
//16
select * from frs where nom like '%n%';
select * from client where nom like '_aa%';
select * from vente where dat='1-OCT-2007';
select count(*) as nbrArticle from article;
select count(*) as nbrVente from vente;


/* TP8 */
//1
select des,frs.nom from article,frs where article.num_f=frs.num_f;
SELECT * FROM Article WHERE num_f IN (SELECT num_f FROM Frs WHERE ville = 'Gabes');
select vente.* from vente,article where vente.num_a=article.num_a and article.couleur='Vert';
SELECT *
FROM Article WHERE num_f IN (SELECT num_f FROM Frs WHERE ville = 'Sousse') OR des LIKE 'A%';
select vente.* from vente,article where vente.num_a=article.num_a and prix_vente>prix_achat*2;
//6
select des,loc,qte,dat
    from vente, magasin, article
    where vente.num_a=article.num_a
    and vente.num_m=magasin.num_m;
//7
select magasin.num_m,sum(vente.prix_vente*vente.qte)
    from magasin, vente
    where magasin.num_m=vente.num_m
    group by vente.num_m;
//8
select dat,sum(qte) as NbrDeVente, sum(prix_vente*qte) as MontantDeVente
    from vente
    group by dat;
//9
select sum(prix_vente*qte) as montantDeVente
    from vente,client
    where vente.num_c=client.num_c
    and ville='Gabes';
//10
select vente.num_a,sum(qte)
    from vente, article
    where vente.num_a=article.num_a
    group by vente.num_a;
//11
select vente.num_a,min(qte)
    from vente, article
    where vente.num_a=article.num_a
    group by vente.num_a;
//12
select vente.num_a,max(qte)
    from vente, article
    where vente.num_a=article.num_a
    and article.couleur='Vert';
//13
select vente.*
    from vente, article, frs, client
    where vente.num_a=article.num_a
    and article.num_f=frs.num_f
    and vente.num_c=client.num_c
    and Client.ville = 'Gabès'
    and frs.ville='Sousse';
//14
select client.num_c
    from client, article, vente
    where vente.num_a=article.num_a
    and vente.num_c=client.num_c
    and article.couleur IN ('verte', 'bleue')
    group by client.num_c;
//15
select vente.*
    from vente, article,frs
    where vente.num_a=article.num_a
    and poids between 200 and 500
    and article.num_f=frs.num_f
    and couleur='Vert'
    and ville in ('Sousse', 'Gabes');
//16
select avg(qte),vente.num_a,vente.num_m
    from vente, article, magasin
    where vente.num_a=article.num_a
    and vente.num_m=magasin.num_m
    group by vente.num_a,vente.num_m;
//17
select num_a, count(*)
    from vente
    group by num_a
    having count(*)>3;
//18
select num_m, sum(prix_vente*qte)
    from vente
    group by num_m
    having sum(prix_vente*qte)>5000;

//19
select vente.num_a
    from vente,frs,article
    where vente.num_a=article.num_a
    and article.num_f=frs.num_f
    and frs.ville='Gebes'
    group by vente.num_a
    having sum(qte)>200;
//20
select nom
    from client
    where ville in
    (select ville
        from client
        where num_c='C2');
    
select c1.nom
    from client c1, client c2
    where c1.ville=c2.ville
    and c2.num_c='C2';


/* TP9 */
//1
select des
    from article
    join vente on vente.num_a=article.num_a
    group by des
    having count(*)>3;
//2
select des
    from article
    where (select count(*) from vente where vente.num_a=article.num_a)
    > (select count(*) from vente where num_a='A1');
//3
select loc
    from magasin
    where num_m in
    (select num_m
        from vente
        group by num_m
        having count(*)>=3);
//4
select num_m,loc
    from magasin
    where num_m in
    (select num_m
        from vente
        where num_a in ('A1','A2')
    );
//5
select num_m, num_a,count(*) as nbrVente
    from vente
    group by num_m, num_a;
//6
select num_m,num_a,sum(qte)
    from vente
    group by num_m,num_a;
//7
select nom
    from frs
    where num_f in
    (select num_f
        from article
        where couleur='Vert');
//8      ????
select num_m
    from (select num_m,count(distinct num_a) as nbrArticle from vente group by num_m)
    where nbrArticle = (select count(distinct num_a) from article)
    ;
//9
select des, poids, couleur
    from article
    where poids>(select avg(poids) from article where couleur='Vert')
    order by des desc;
//10   ??????
select des,poids
    from article,frs
    where article.num_f=frs.num_f
    and length(frs.nom)=10
    and poids = (select max(poids) from article );
//11    ?????
select loc
    from magasin
    where num_m =
    (select num_m
        from vente
        group by num_m
        order by count(distinct num_a) desc
        limit 1
        );
//12       ?????
select num_m
    from magasin
    where not
    (select * from vente, article
    where magasin);
//13
SELECT des, couleur
FROM Article
WHERE prix_achat > (
    SELECT prix_achat
    FROM Article
    WHERE couleur = 'verte'
);
//14
SELECT V1.*
    FROM Vente V1, Vente V2
    WHERE V1.num_m = 'M1' 
    AND V1.prix_vente * V1.qte = V2.prix_vente * V2.qte 
    AND V2.num_m = 'M2';
//15
SELECT DISTINCT num_a
    FROM Vente
    WHERE num_m = 'M1'
    AND num_a NOT IN (
        SELECT num_a
        FROM Vente
        WHERE num_m = 'M3'
    );
//16

//17

//18

//19
SELECT F1.nom, F2.nom
FROM Frs F1, Frs F2
WHERE F1.ville = F2.ville;
//20
SELECT des
    FROM Article
    WHERE num_a NOT IN (SELECT num_a FROM Vente);

select * from magasin;
select * from frs;
select * from client;
select * from article;
select * from vente;

select * from frs_sousse;






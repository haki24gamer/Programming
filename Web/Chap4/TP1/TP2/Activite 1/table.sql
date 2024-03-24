/*Creation du table filiere*/
CREATE TABLE filiere (
    num_filiere int,
    nom_filiere varchar(50),
    CONSTRAINT pk_fil PRIMARY KEY (num_filiere)
);

/*Creation du table etudiant*/
CREATE TABLE etudiant (
    numero_etudiant int,
    nom_etudiant varchar(50),
    mot_passe_etudiant varchar(50),
    sexe_etudiant varchar(50),
    email_etudiant varchar(50),
    adresse_etudiant varchar(50),
    num_filiere varchar(50),
    CONSTRAINT pk_et PRIMARY KEY (numero_etudiant),
    CONSTRAINT fk_fil FOREIGN KEY (num_filiere) REFERENCES filiere(num_filiere)
);























CREATE TABLE enseignant(
    numero_enseignant int,
    nom_enseignant varchar(50),
    passe_enseignant varchar(50),
    sexe_enseignant varchar(50),
    email_enseignant varchar(50),
    adresse_enseignant varchar(50),
    telmobile_enseignant int,
    tel
)

CREATE TABLE module(
    code_module int,
    nom_module varchar(50),
    coeff_module int,
    volumehoraire int,
    numero_enseignant int,
    CONSTRAINT pk_modu PRIMARY KEY (code_module),
    CONSTRAINT fk_ens FOREIGN KEY (numero_enseignant) REFERENCES enseignant(numero_enseignant)
)
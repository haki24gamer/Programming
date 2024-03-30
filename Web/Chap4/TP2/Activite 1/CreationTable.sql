CREATE TABLE Filiere(
    num_filiere INT,
    nom_filiere VARCHAR(50),
    CONSTRAINT pk_numfil PRIMARY KEY (num_filiere)
);

CREATE TABLE Etudiant(
    numero_etudiant INT,
    nom_etudiant VARCHAR(50),
    mot_passe_etudiant VARCHAR(50),
    sexe_etudiant VARCHAR(50),
    email_etudiant VARCHAR(50),
    adresse_etudiant VARCHAR(50),
    num_filiere INT,
    CONSTRAINT pk_numet PRIMARY KEY (numero_etudiant),
    CONSTRAINT fk_numfil FOREIGN KEY (num_filiere) REFERENCES Filiere(num_filiere)
);

CREATE TABLE Enseignant(
    numero_enseignant INT,
    nom_enseignant VARCHAR(50),
    sexe_enseignant VARCHAR(50),
    email_enseignant VARCHAR(50),
    adresse_enseignant VARCHAR(50),
    tel_enseignant INT,
    grade_enseignant VARCHAR(50),
    CONSTRAINT pk_numens PRIMARY KEY (numero_enseignant)
);

ALTER TABLE Enseignant
ADD passe_enseignant VARCHAR(50);

CREATE TABLE Module(
    code_module INT,
    nom_module VARCHAR(50),
    coeff_module INT,
    volumehoraire INT,
    numero_enseignant INT,
    CONSTRAINT pk_codemod PRIMARY KEY (code_module),
    CONSTRAINT fk_numens FOREIGN KEY (numero_enseignant) REFERENCES Enseignant(numero_enseignant)
);

CREATE TABLE Note(
    num_note INT,
    controle_continu INT,
    controle_finale INT,
    semestre INT,
    annee VARCHAR(50),
    numero_etudiant INT,
    code_module INT,
    CONSTRAINT pk_numnot PRIMARY KEY(num_note),
    CONSTRAINT fk_numet FOREIGN KEY(numero_etudiant) REFERENCES Etudiant(numero_etudiant),
    CONSTRAINT fk_codemod FOREIGN KEY(code_module) REFERENCES Module(code_module)
);
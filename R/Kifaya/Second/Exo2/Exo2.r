#Exercice 2#
#1
stu <- read.table('etudiant.txt', header=TRUE)
stu

#2
mean(stu$tuition) # la moyenne des frais de scolarité de tous les étudiants
mean(stu$tuition[stu$female==1]) # la moyenne des frais de scolarité pour les étudiantes uniquement pour les etudiants femelles
mean(stu$tuition[stu$ed>=14]) # la moyenne des frais de scolarité pour les étudiants ayant 14 années d'éducation ou plus
mean(stu$tuition[!(stu$ed<14)])  # la moyenne des frais de scolarité pour les étudiants ayant 14 ans ou plus d'éducation
quantile(stu$dist[stu$urban==1],0.25) # le premier quartile (Q1) de la distance entre l'université et le domicile des étudiants urbains
sd(stu$dist[stu$hispanic==1 & stu$tuition>1]) # l'écart-type de la distance entre l'université et le domicile pour les étudiants hispaniques dont les frais de scolarité sont supérieurs à 1 mille dollars

#3
median(stu$ed[stu$female==1 & stu$momcoll == 1])
quantile(stu$ed[stu$hispanic == 1 & stu$tuition > 1], 0.75)

#4
black_hispanic_stu <- subset(stu, black == 1 & hispanic == 1)
if (nrow(black_hispanic_stu) == 0) {
  cat("Aucun étudiant n'a été codé simultanément comme black et hispanic.\n")
} else {
  cat("Attention: Certains étudiants ont été codés simultanément comme black et hispanic.\n")
}

#5
tab1<-stu[,c(8:10)] #Cette commande crée un nouveau data frame "tab1" en sélectionnant les colonnes 8 à 10 (dist, tuition, ed) du data frame "stu"
head(tab1) # Afficher les 6 premieres lignes du tab1
tab2<-stu[-c(1,3),] #Cette commande crée un nouveau data frame "tab2" en excluant les lignes 1 et 3 du data frame "stu"
head(tab2) # Afficher les 6 premieres lignes du tab2
tab3<-stu[stu$female==1,]  # Cette commande crée un nouveau data frame "tab3" en sélectionnant uniquement les lignes où le sexe est femelle
head(tab3) # Afficher les 6 premieres lignes du tab3
tab4<-tab3[,-1] # Cette commande crée un nouveau data frame "tab4" en excluant la première colonne du data frame "tab3" (la colonne "female")
head(tab4 )# Afficher les 6 premieres lignes du tab4
tab5<-stu[stu$female==1,-1] # Cette commande crée un nouveau data frame "tab5" en sélectionnant uniquement les lignes où l eleve est une femelle, puis en excluant la première colonne de ce sous-ensemble de données
head(tab5) # Afficher les 6 premieres lignes du tab5
tab6<-stu[stu$county==28&stu$tuition>=1.2,-(1:3)] #Cette commande crée un nouveau data frame "tab6" en sélectionnant uniquement les lignes où le numéro de code du comté égale à 28 et le frais de scolarité est supérieure ou égale à 1.2 dans le data frame "stu", puis en excluant les trois premières colonnes de ce sous-ensemble de données.
head(tab6) # Afficher les 6 premieres lignes du tab6

#6
tab7 <- stu[stu$hispanic == 1 & stu$incomehi == 1, ]
tab7 <- tab7[, !(names(tab7) %in% c("hispanic", "black", "incomehi"))]
tab7
nombre_individus <- nrow(tab7)
nombre_individus

#7
bytest <- read.table('bytest.txt', header=TRUE)
head(bytest)
studentbis <- cbind(stu, bytest)
head(studentbis)

#8
commu <- ifelse(stu$black == 1, "Black", ifelse(stu$hispanic == 1, "Hispanic", "White"))
commu
stu$commu <- commu
stu

#9 Probleme
moyenne <- by(studentbis$score, commu, mean)
moyenne

#10
result <- by(studentbis$score, studentbis$female, FUN = function(x) quantile(x, c(0.25, 0.5, 0.75)))
result

#11
et <- function(x) {
  sqrt( (length(x)-1)/length(x) ) * sd(x)
  }

result <- by(studentbis$score, studentbis$female, FUN = et)
result

#12
par.sup <- ifelse(studentbis$dadcoll == 1 | studentbis$momcoll == 1, 1, 0)
par.sup
deciles_par_sup <- by(studentbis$score, par.sup, FUN = function(x) quantile(x, seq(0, 1, 0.1)))
deciles_par_sup




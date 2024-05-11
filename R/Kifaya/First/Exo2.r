

###Partie 1
#1
Quetelet<-read.csv(file.choose())
Quetelet

#2
Quetelet$taille
Quetelet$poids
Quetelet$sexe

taille<-Quetelet$taille
poids<-Quetelet$poids
sexe<-Quetelet$sexe

#3
length(Quetelet$taille)

#4
summary(taille)
summary(poids)

#5
genre<-split(Quetelet,sexe)

#6
nrow(genre$f)
nrow(genre$h)

###Partie 2

imc<-poids/(taille/100)**2
#7
summary(imc)
genreimc<-split(imc,sexe)
genreimc
lapply(genreimc,summary)
#8
hist(imc,col=grey(0.8))
#9
par(mfcol=c(2,2))
hist(imc[sexe=="h"],main="homme",xlab="imc",xlim=c(16,27),col=grey(0.9))

hist(imc[sexe=="f"],main="femme",xlab="imc",xlim=c(16,27),col=grey(0.9))



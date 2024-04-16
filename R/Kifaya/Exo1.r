#Debut
install.packages("HSAUR")
library(HSAUR)
data("Forbes2000", package="HSAUR")

#1
Forbes2000 #Pour imprimer le dataset Forbes2000
    
#2
str(Forbes2000) #Pour afficher la structure de Forbes2000

#3
class(Forbes2000) #Pour afficher la classe ou type de Forbes2000

#4
nrow(Forbes2000) #Forbes2000 comporte 2000 lignes

#5
ncol(Forbes2000) #Forbes2000 comporte 8 colonnes

#6
names(Forbes2000) #les noms des colonnes sont "rank", "name", "country", "category", "sales", "profits", "assets", "marketvalue"
sapply(Forbes2000, class) #Pour afficher les classes des objets

#7
length(Forbes2000$country) #Pour afficher la longueur d une colonne

#8
Forbes2000$name[1] #Le nom du premiere entreprise : Citigroup

#9
length(unique(Forbes2000$category)) #Y en a 27 categories

#10
colnames(Forbes2000)

#11
levels(Forbes2000$category)

#12
class(Forbes2000$sales)

#13
summary(Forbes2000$sales)

#14
summary(Forbes2000)

#15
layout(matrix(1 :2, nrow = 2))
hist(Forbes2000$marketvalue)
hist(log(Forbes2000$marketvalue))
#Elles affichent deux histrogramme un avec le marketvalue et l autre son logarithme

#16
hist(Forbes2000$marketvalue)
hist(log(Forbes2000$marketvalue))
#Seulement le deuxieme histogramme s affiche

#17
plot(log(Forbes2000$marketvalue), Forbes2000$sales)

#18
boxplot(log(Forbes2000$marketvalue)~Forbes2000$country=="Germany")
boxplot(log(Forbes2000$marketvalue)~Forbes2000$country=="India")
boxplot(log(Forbes2000$marketvalue)~Forbes2000$country=="Turkey")
boxplot(log(Forbes2000$marketvalue)~Forbes2000$country=="United Kingdom")






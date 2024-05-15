#Exercice 1#
#1
data <- read.csv('television.txt', sep = ";")
data

#2
nrow(data)

#3
str(data) 

#4
summary(data)
unique(data$Diplome)

#5
hist(data$DureeTV, main = "La duree quotidienne devant la television", xlab = "Duree devant la television", ylab = "Frequence")

#6
sum(data$DureeTV>=2*60)

#7
dataF = subset(data, Genre=="F")
dataF

#8
dataF <- dataF[, -which(names(dataF)=="Genre")]
dataF

#9
boxplot(data$DureeTV ~ data$Foyers, data = data, 
        main = "Durée quotidienne devant la TV en fonction du nombre de personnes dans le foyer",
        xlab = "Nombre de personnes dans le foyer", ylab = "Durée TV quotidienne",
        col = "skyblue", boxwex = 0.5, medcol = "darkblue", whiskcol = "darkblue")

#10
sous_ensemble <- subset(data, Foyers == 4)
moyenne_duree_tv <- mean(sous_ensemble$DureeTV)
moyenne_arrondie <- round(moyenne_duree_tv, digits = 1)
moyenne_arrondie

#11
Vec <- ifelse(data$Diplome %in% c("Bac", "SupBac+2", "Bac+2"), 1, 0)
Vec

#12
hommes <- subset(data, Genre == "H")
nombre_hommes_bac_plus <- sum(hommes$Diplome %in% c("Bac", "SupBac+2", "Bac+2"))
proportion_hommes_bac_plus <- nombre_hommes_bac_plus / nrow(hommes)
proportion_arrondie <- round(proportion_hommes_bac_plus, digits = 3)
proportion_arrondie

#13
table_contingence <- table(data$Genre, data$Diplome)
table_contingence

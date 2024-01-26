#1
pieces=sample(c("face","pile"),1000,replace = T) #Simulier la lance d une piece 1000 fois
#print(pieces)

distpieces=table(pieces) #mettre la resultat dans un tableau
#print(distpieces)
#barplot(distpieces)

#print(sum(pieces=="pile")/1000)



#2
de=sample(1:6, 1000, replace = T)
distde=table(de)
barplot(distde)
sum(de==4)/1000



#3

#print(sum(S==7)/1000)

#4
n=30
size=1
p=0.3
X=rbinom(n,size,p) ###n est le taille d echontillon ###size est le nombre d essaie ###p est le parametre
#print(X)
#print(table(X)/n)

#5
n=30
size=10
p=0.3
X=rbinom(n,size,p) ###n est le taille d echontillon ###size est le nombre d essaie ###p est le parametre
#print(X)
#print(table(X)/n)

#6
n=30
p=0.3
X=rgeom(n,p)
table(X)/2
esp=1/2
Var=(1-p)/(p^2)

#7
X=rhyper(1000,3, 5,4)
#print(X)

#8

X=dbinom(20:30, 100, 0.52)
print(sum(X))
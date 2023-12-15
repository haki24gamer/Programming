age=c(20,22,26,28)
taille=c(155,150,170,165)

###Question 1###
#Fonction
moyenne=function(x) {
    long=length(x)
    res=sum(x)/long
    return(res)
}
#Affectation
ageMoy=moyenne(age) #mean(age)
tailleMoy=moyenne(taille) #mean(taille)

###Question 2###
#Fonction
vari=function(x){
    moy=mean(x)
    long=length(x)
    somme=0
    for (i in x) {
       somme=((i-moy)*(i-moy))
    }
    res=sum(somme)/long
    return(res)
}
#Affectation
ageVar=var(age)
tailleVar=var(taille)

print(ageVar)
print(tailleVar)
print(vari(age))
print(vari(taille))
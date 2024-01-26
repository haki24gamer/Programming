age=c(20,22,26,28)
taille=c(155,150,170,165)

###Question 1###
ageMoy=mean(age)
tailleMoy=mean(taille)

###Question 2###
ageVar=var(age)
tailleVar=var(taille)

###Question 3###
Covarience=cor(taille,age)

###Question 4###
Corr=function(x,y) {
    valX=sqrt(var(x))
    valY=sqrt(var(y))
    Rxy=(cor(x,y))/(valX*valY)
    return(Rxy)
}

print(Corr(age,taille))
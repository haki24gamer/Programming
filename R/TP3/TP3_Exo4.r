#Q1 salaire moy
nbrsomme = c(11,26,63,81,35,21,13)
centres = c(35,45,55,65,75,85,95)
salairemoy=function(n,c) {
    res = sum(n*c)/sum(n)
    return(res)
}
salairemoy(nbrsomme,centres)

#Q2
salaire=c(30,40,50,60,70,80,90)
nbpersonnes=c(11,26,63,81,35,21,13)
ECC=cumsum(nbpersonnes)
plot(salaire,ECC,type="l",lwd=4)

abline(v = 63.08, col="green", lwd=2)
abline(v = 63.72, col="red", lwd=2)
abline(v = 63.81, col="blue", lwd=2)
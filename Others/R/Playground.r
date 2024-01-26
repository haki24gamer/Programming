nbperson=c(11,26,63,81,35,21,13)
nbperson
ECC=cumsum(nbperson)
ECC

#median
med=(sum(nbperson)/2)
#moy
moy=sum(nbperson)/length(nbperson)
#salaire dominant
dom=max(nbperson)
#polygone
plot(nbperson)
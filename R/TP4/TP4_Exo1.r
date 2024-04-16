NbrPiece=1:5;
NbrMaison=c(50,30,120,200,20)

###Question 1###
#ECC=cumsum(NbrMaison)
#median(NbrMaison)
ECC=cumsum(NbrMaison*NbrPiece)

###Question 4###
moyenne=sum(NbrMaison*NbrPiece)/sum(NbrMaison)


Var=sum((NbrMaison*(NbrPiece-moyenne))**2)/sum(NbrMaison)
print(Var)

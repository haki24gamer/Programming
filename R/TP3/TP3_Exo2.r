##Q1
arbre = c(1,2,4,1,6,3,2,1,2,0,1,2,2,1,3,0,3,2,1,2,2,3,2,3)
#print(arbre)

##Q2
croi=(sort(arbre))
#print(crois)

##Q3
n=length(arbre)
#print(n)

##Q4
eff=table(arbre)
print(eff)

##Q5
freq=eff/n
effcum=sort(eff)
#print(freq)
#print(effcum)
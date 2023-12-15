sinus = function(x) {
    return(sin(x))
}

#1
x1 = seq(0, 4*pi,length=100)
y1 = sinus(x1)
plot(x1, y1, type='l', col='red', lwd=4, xlab='x', ylab='sin(x)', main='graphe des fonctions sinus et cosinus')

#2
y2 = cos(x1)
lines(x1,y2, col='blue', type='l', lwd=4)

#3
abline(h=c(-1,1), lwd=4, col='green')

legend('bottomleft', c('sinus', 'cosinus'), col=c('red','blue'),lwd=4)
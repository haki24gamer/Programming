x=c(0:10)

sinus=function(var){
    res = sin(var)
    return(res)
}
y = sinus(x)

plot(x,y, type="b", lwd=4, col="blue")
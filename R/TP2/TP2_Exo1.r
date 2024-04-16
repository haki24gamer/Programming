z = function(x,y) {
    return((10*(sin(sqrt(x*x+y*y))))/sqrt(x*x+y*y))
}

x=seq(-10, 10, length=200)
y=seq(-10, 10, length=200)

z1=outer(x, y, z)
head(z1)
persp(x,y,z1)
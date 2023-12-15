Fibonacci=function(n) {
    res=rep(0, n); res[2]=1
    for (i in 3:n) res[i]=res[i-1]+res[i-2]
    return(res)
}

#print(Fibonacci(0))
#print(Fibonacci(1))
print(Fibonacci(10))
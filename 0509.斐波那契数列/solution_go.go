func fib(n int) int {
    if n<=1 {
        return n
    }
    var a,b int=0,1
    for i:=2;i<=n;i++ {
        tmp:=b
        b+=a
        a=tmp
    }
    return b
}

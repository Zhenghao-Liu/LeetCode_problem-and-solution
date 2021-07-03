func hammingDistance(x int, y int) int {
    res,ans:=x^y,0
    for i:=0;i<31;i++ {
        if (res&1)!=0 {
            ans++
        }
        res>>=1
    }
    return ans
}
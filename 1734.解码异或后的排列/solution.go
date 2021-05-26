func decode(encoded []int) []int {
    all:=0
    sz:=len(encoded)+1
    for i:=1;i<=sz;i++ {
        all^=i
    }
    for i:=1;i<sz-1;i+=2 {
        all^=encoded[i]
    }
    ans:=make([]int,sz)
    ans[0]=all
    for i:=1;i<sz;i++ {
        ans[i]=ans[i-1]^encoded[i-1]
    }
    return ans
}
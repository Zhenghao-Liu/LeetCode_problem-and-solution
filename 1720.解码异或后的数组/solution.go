func decode(encoded []int, first int) []int {
    sz:=len(encoded)+1
    ans:=make([]int,sz)
    ans[0]=first
    for i:=1;i<sz;i++ {
        ans[i]=ans[i-1]^encoded[i-1]
    }
    return ans
}
func totalHammingDistance(nums []int) int {
    var one [32]int
    for _,i:=range nums {
        idx:=0
        for i!=0 {
            if (i&1)!=0 {
                one[idx]++
            }
            idx++
            i>>=1
        }
    }
    ans,sz:=0,len(nums)
    for _,i:=range one {
        ans+=i*(sz-i)
    }
    return ans
}
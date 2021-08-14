func minPairSum(nums []int) int {
    sort.Ints(nums)
    ans:=0
    sz:=len(nums)
    for i:=0;i<sz/2;i++ {
        ans=max(ans,nums[i]+nums[sz-1-i])
    }
    return ans
}

func max(a,b int) int {
    if a>b {
        return a
    }
    return b
}
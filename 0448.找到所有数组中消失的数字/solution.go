func findDisappearedNumbers(nums []int) []int {
    for _,i:=range nums{
        idx:=abs(i)-1
        if nums[idx]>0 {
            nums[idx]=-nums[idx]
        }
    }
    var ans []int
    for i:=range nums{
        if nums[i]>0 {
            ans=append(ans,i+1)
        }
    }
    return ans
}

func abs(n int) int {
    if n<0 {
        return -n
    }
    return n
} 

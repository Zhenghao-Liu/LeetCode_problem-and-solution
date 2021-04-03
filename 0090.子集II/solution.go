var ans [][]int
var cur []int
var sz int

func subsetsWithDup(nums []int) [][]int {
	sort.Ints(nums)
	ans = make([][]int, 0)
	cur = make([]int, 0, len(nums))
	sz = len(nums)
	dfs(nums, 0, false)
	return ans
}

func dfs(nums []int, i int, chosePre bool) {
	if i == sz {
		ans = append(ans, append([]int{}, cur...))
		return
	}
	dfs(nums, i+1, false)
	if !chosePre && i > 0 && nums[i] == nums[i-1] {
		return
	}
	cur = append(cur, nums[i])
	dfs(nums, i+1, true)
	cur = cur[:len(cur)-1]
}
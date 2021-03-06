func nextGreaterElements(nums []int) []int {
	sz := len(nums)
	sta := make([]int, 0, sz*2)
	for i := sz - 2; i >= 0; i-- {
		cur := nums[i]
		for len(sta) != 0 && cur >= sta[len(sta)-1] {
			sta = sta[:len(sta)-1]
		}
		sta = append(sta, cur)
	}
	ans := make([]int, sz)
	for i := sz - 1; i >= 0; i-- {
		cur := nums[i]
		for len(sta) != 0 && cur >= sta[len(sta)-1] {
			sta = sta[:len(sta)-1]
		}
		if len(sta) != 0 {
			ans[i] = sta[len(sta)-1]
		} else {
			ans[i] = -1
		}
		sta = append(sta, cur)
	}
	return ans
}

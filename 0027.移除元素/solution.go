func removeElement(nums []int, val int) int {
	sz := len(nums)
	s, f := 0, 0
	for f < sz {
		if nums[f] == val {
			f++
		} else {
			nums[s] = nums[f]
			s++
			f++
		}
	}
	return s
}
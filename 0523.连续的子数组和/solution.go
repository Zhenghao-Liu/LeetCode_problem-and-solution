func checkSubarraySum(nums []int, k int) bool {
	mp := make(map[int]int)
	sum := 0
	mp[0] = -1
	for i := range nums {
		sum += nums[i]
		sum %= k
		if pos, ok := mp[sum]; ok {
			if i-pos >= 2 {
				return true
			}
		} else {
			mp[sum] = i
		}
	}
	return false
}
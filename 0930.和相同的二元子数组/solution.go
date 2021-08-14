func numSubarraysWithSum(nums []int, goal int) int {
	sum, ans := 0, 0
	mp := make(map[int]int, 3e4)
	mp[0] = 1
	for _, i := range nums {
		sum += i
		if cnt, ok := mp[sum-goal]; ok {
			ans += cnt
		}
		mp[sum]++
	}
	return ans
}
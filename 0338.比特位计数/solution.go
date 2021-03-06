func countBits(num int) []int {
	ans := make([]int, num+1)
	ans[0] = 0
	for i := 1; i <= num; i++ {
		add := 0
		if (i & 1) != 0 {
			add = 1
		}
		ans[i] = ans[i>>1] + add
	}
	return ans
}

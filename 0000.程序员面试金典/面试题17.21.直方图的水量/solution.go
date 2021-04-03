func trap(height []int) int {
	sz := len(height)
	l2r, r2l := make([]int, sz), make([]int, sz)
	for i := 1; i < sz; i++ {
		l2r[i] = max(l2r[i-1], height[i-1])
	}
	for i := sz - 2; i >= 0; i-- {
		r2l[i] = max(r2l[i+1], height[i+1])
	}
	var ans int
	for i := 1; i < sz-1; i++ {
		diff := min(l2r[i], r2l[i]) - height[i]
		if diff > 0 {
			ans += diff
		}
	}
	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
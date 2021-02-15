func equalSubstring(s string, t string, maxCost int) int {
	sz := len(s)
	cst := make([]int, sz)
	for i := 0; i < sz; i++ {
		cst[i] = abs(int(s[i]) - int(t[i]))
	}
	var ans int
	var l, r int
	var sum int
	for ; l < sz; l++ {
		for ; r < sz && sum+cst[r] <= maxCost; r++ {
			sum += cst[r]
		}
		ans = max(ans, r-l)
		sum -= cst[l]
	}
	return ans
}

func abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

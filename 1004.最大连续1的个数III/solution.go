func longestOnes(A []int, K int) int {
	sz := len(A)
	l, r := 0, 0
	ans, cnt := 0, 0
	for l < sz {
		for r < sz && cnt+(A[r]^1) <= K {
			cnt += 1 - A[r]
			r++
		}
		ans = max(ans, r-l)
		cnt -= 1 - A[l]
		l++
	}
	return ans
}

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

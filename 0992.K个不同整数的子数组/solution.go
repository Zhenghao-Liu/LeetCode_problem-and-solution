func subarraysWithKDistinct(A []int, K int) int {
	return solve(A, K) - solve(A, K-1)
}

func solve(A []int, k int) int {
	if k == 0 {
		return 0
	}
	sz := len(A)
	cnt := make([]int, sz+1)
	num := 0
	ans := 0
	l, r := 0, 0
	for r < sz {
		if cnt[A[r]] == 0 {
			num++
		}
		cnt[A[r]]++
		r++
		for num > k {
			cnt[A[l]]--
			if cnt[A[l]] == 0 {
				num--
			}
			l++
		}
		ans += r - l
	}
	return ans
}

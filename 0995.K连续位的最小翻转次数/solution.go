func minKBitFlips(A []int, K int) int {
	sz := len(A)
	diff := make([]int, sz)
	diff[0] = A[0]
	for i := 1; i < sz; i++ {
		diff[i] = A[i] - A[i-1]
	}
	var ans, cur int
	for i := 0; i < sz; i++ {
		cur += diff[i]
		if cur%2 == 0 {
			ans++
			st, ed := i, i+K
			diff[st]++
			cur++
			if ed < sz {
				diff[ed]--
			} else if ed > sz {
				return -1
			}
		}
	}
	return ans
}

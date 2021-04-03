func clumsy(N int) int {
	ans := make([]int, 0, N)
	ans = append(ans, N)
	N--
	idx := -1
	for N != 0 {
		idx = (idx + 1) % 4
		switch idx {
		case 0:
			ans[len(ans)-1] *= N
		case 1:
			ans[len(ans)-1] /= N
		case 2:
			ans = append(ans, N)
		case 3:
			ans = append(ans, -N)
		}
		N--
	}
	res := 0
	for _, i := range ans {
		res += i
	}
	return res
}
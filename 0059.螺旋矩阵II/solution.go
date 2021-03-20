var dir = [][]int{[]int{0, 1}, []int{1, 0}, []int{0, -1}, []int{-1, 0}}

func generateMatrix(n int) [][]int {
	ans := make([][]int, n)
	for i := range ans {
		ans[i] = make([]int, n)
	}
	i, j, k := 0, 0, 0
	num, all := 1, n*n
	for num <= all {
		ans[i][j] = num
		num++
		ii, jj := i+dir[k][0], j+dir[k][1]
		if !(ii >= 0 && ii < n && jj >= 0 && jj < n) || (ans[ii][jj] != 0) {
			k = (k + 1) % 4
		}
		i, j = i+dir[k][0], j+dir[k][1]
	}
	return ans
}

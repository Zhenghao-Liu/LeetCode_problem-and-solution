func transpose(matrix [][]int) [][]int {
	row := len(matrix)
	col := len(matrix[0])
	ans := make([][]int, col)
	for i := range ans {
		ans[i] = make([]int, row)
	}
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			ans[j][i] = matrix[i][j]
		}
	}
	return ans
}

const INF = 0x3f3f3f3f

var dir = [][]int{[]int{0, 1}, []int{1, 0}, []int{0, -1}, []int{-1, 0}}

func spiralOrder(matrix [][]int) []int {
	row, col := len(matrix), len(matrix[0])
	idx := 0
	all := row * col
	ans := make([]int, all)
	i, j, k := 0, 0, 0
	for idx < all {
		ans[idx] = matrix[i][j]
		idx++
		matrix[i][j] = INF
		ii, jj := i+dir[k][0], j+dir[k][1]
		if !(ii >= 0 && ii < row && jj >= 0 && jj < col) || matrix[ii][jj] == INF {
			k = (k + 1) % 4
		}
		i += dir[k][0]
		j += dir[k][1]
	}
	return ans
}

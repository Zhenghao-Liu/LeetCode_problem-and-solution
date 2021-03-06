type NumMatrix struct {
	prefix [][]int
}

func Constructor(matrix [][]int) NumMatrix {
	row, col := len(matrix), 0
	if row != 0 {
		col = len(matrix[0])
	}
	var ans NumMatrix
	ans.prefix = make([][]int, row+1)
	for i := range ans.prefix {
		ans.prefix[i] = make([]int, col+1)
	}
	for j := 0; j < col; j++ {
		ans.prefix[1][j+1] = ans.prefix[1][j] + matrix[0][j]
	}
	for i := 0; i < row; i++ {
		ans.prefix[i+1][1] = ans.prefix[i][1] + matrix[i][0]
	}
	for i := 1; i < row; i++ {
		for j := 1; j < col; j++ {
			ans.prefix[i+1][j+1] = ans.prefix[i+1][j] + ans.prefix[i][j+1] - ans.prefix[i][j] + matrix[i][j]
		}
	}
	return ans
}

func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
	return this.prefix[row2+1][col2+1] + this.prefix[row1][col1] - this.prefix[row2+1][col1] - this.prefix[row1][col2+1]
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * obj := Constructor(matrix);
 * param_1 := obj.SumRegion(row1,col1,row2,col2);
 */

func searchMatrix(matrix [][]int, target int) bool {
	row, col := len(matrix), len(matrix[0])
	l, r := 0, row*col-1
	for l < r {
		mid := l + (r-l)/2
		x, y := mid/col, mid%col
		if matrix[x][y] >= target {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return matrix[l/col][l%col] == target
}

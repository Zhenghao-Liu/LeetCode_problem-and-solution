// Ax+By+C=0
// A = Y2 - Y1
// B = X1 - X2
// C = X2*Y1 - X1*Y2
func checkStraightLine(coordinates [][]int) bool {
	size := len(coordinates)
	x1 := coordinates[0][0]
	y1 := coordinates[0][1]
	x2 := coordinates[1][0]
	y2 := coordinates[1][1]
	A := y2 - y1
	B := x1 - x2
	C := x2*y1 - x1*y2
	for i := 2; i < size; i++ {
		x := coordinates[i][0]
		y := coordinates[i][1]
		if A*x+B*y+C != 0 {
			return false
		}
	}
	return true
}

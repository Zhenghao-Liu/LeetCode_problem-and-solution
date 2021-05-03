func judgeSquareSum(c int) bool {
	up := int(math.Sqrt(float64(c)))
	for i := 0; i <= up; i++ {
		a, b := i*i, c-i*i
		if a > b {
			break
		}
		c := int(math.Sqrt(float64(b)))
		if c*c == b {
			return true
		}
	}
	return false
}
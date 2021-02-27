func maxSatisfied(customers []int, grumpy []int, X int) int {
	var all int
	sz := len(customers)
	for i := 0; i < sz; i++ {
		if grumpy[i] == 0 {
			all += customers[i]
		}
	}
	var ans = all
	var win int
	for i := 0; i < X-1; i++ {
		if grumpy[i] == 1 {
			win += customers[i]
		}
	}
	for i := X - 1; i < sz; i++ {
		if grumpy[i] == 1 {
			win += customers[i]
		}
		if i-X >= 0 && grumpy[i-X] == 1 {
			win -= customers[i-X]
		}
		ans = max(ans, win+all)
	}
	return ans
}
func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

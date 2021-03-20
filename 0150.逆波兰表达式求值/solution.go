func evalRPN(tokens []string) int {
	sta := make([]int, 0)
	for _, i := range tokens {
		switch i {
		case "+":
			sta[len(sta)-2] = sta[len(sta)-2] + sta[len(sta)-1]
			sta = sta[:len(sta)-1]
		case "-":
			sta[len(sta)-2] = sta[len(sta)-2] - sta[len(sta)-1]
			sta = sta[:len(sta)-1]
		case "*":
			sta[len(sta)-2] = sta[len(sta)-2] * sta[len(sta)-1]
			sta = sta[:len(sta)-1]
		case "/":
			sta[len(sta)-2] = sta[len(sta)-2] / sta[len(sta)-1]
			sta = sta[:len(sta)-1]
		default:
			num, _ := strconv.Atoi(i)
			sta = append(sta, num)
		}
	}
	return sta[0]
}

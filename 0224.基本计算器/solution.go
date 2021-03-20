func calculate(s string) int {
	var ans int
	num, sign := 0, 1
	sta := make([]int, 0)
	sz := len(s)
	for i := 0; i < sz; i++ {
		if s[i] == '+' {
			sign = 1
		} else if s[i] == '-' {
			sign = -1
		} else if s[i] >= '0' && s[i] <= '9' {
			for i < sz && s[i] >= '0' && s[i] <= '9' {
				num = num*10 + int(s[i]-'0')
				i++
			}
			i--
			ans += num * sign
			num = 0
			sign = 1
		} else if s[i] == '(' {
			sta = append(sta, ans)
			sta = append(sta, sign)
			ans = 0
			sign = 1
		} else if s[i] == ')' {
			cur := ans
			ans = sta[len(sta)-2] + sta[len(sta)-1]*cur
			sta = sta[:len(sta)-2]
		}
	}
	return ans
}

func calculate(s string) int {
	sta := make([]int, 0)
	var num int
	var sign byte = '+'
	sz := len(s)
	for i := 0; i < sz; i++ {
		if s[i] == ' ' {
			continue
		} else if s[i] >= '0' && s[i] <= '9' {
			for i < sz && s[i] >= '0' && s[i] <= '9' {
				num = num*10 + int(s[i]-'0')
				i++
			}
			i--
			switch sign {
			case '+':
				sta = append(sta, num)
			case '-':
				sta = append(sta, -num)
			case '*':
				sta[len(sta)-1] *= num
			case '/':
				sta[len(sta)-1] /= num
			}
			num = 0
			sign = '+'
		} else {
			sign = s[i]
		}
	}
	var ans int
	for _, i := range sta {
		ans += i
	}
	return ans
}

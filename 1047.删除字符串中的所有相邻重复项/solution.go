func removeDuplicates(S string) string {
	ans := make([]rune, 0, len(S))
	for _, i := range S {
		ans = append(ans, i)
		sz := len(ans)
		for sz >= 2 && ans[sz-1] == ans[sz-2] {
			ans = ans[:sz-2]
			sz -= 2
		}
	}
	return string(ans)
}

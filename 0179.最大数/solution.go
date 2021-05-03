func largestNumber(nums []int) string {
	vec := make([]string, len(nums))
	for i, v := range nums {
		vec[i] = strconv.Itoa(v)
	}
	sort.Slice(vec, func(a, b int) bool {
		return vec[a]+vec[b] > vec[b]+vec[a]
	})
	if n, _ := strconv.Atoi(vec[0]); n == 0 {
		return "0"
	}
	ans := make([]byte, 0)
	for _, i := range vec {
		ans = append(ans, []byte(i)...)
	}
	return string(ans)
}
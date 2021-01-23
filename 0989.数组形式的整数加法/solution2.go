const MAXN = 1e4 + 1
func addToArrayForm(A []int, K int) []int {
	ans := make([]int, 0, MAXN)
	p := len(A) - 1
	var a, b, sum, carry int
	for p >= 0 || K > 0 {
		if p >= 0 {
			a = A[p]
		} else {
			a = 0
		}
		if K > 0 {
			b = K % 10
		} else {
			b = 0
		}
		sum = a + b + carry
		ans = append(ans, sum%10)
		carry = sum / 10
		p--
		K /= 10
	}
	if carry == 1 {
		ans = append(ans, 1)
	}
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return ans
}

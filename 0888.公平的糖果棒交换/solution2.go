func fairCandySwap(A []int, B []int) []int {
	var sumA, sumB int
	for _, i := range A {
		sumA += i
	}
	mp := make(map[int]bool)
	for _, i := range B {
		sumB += i
		mp[i] = true
	}
	for _, i := range A {
		tar := sumB - sumA + 2*i
		if tar%2 == 0 {
			tar /= 2
			_, ok := mp[tar]
			if ok {
				return []int{i, tar}
			}
		}
	}
	return []int{}
}

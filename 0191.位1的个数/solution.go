func hammingWeight(num uint32) int {
	ans := 0
	for num != 0 {
		if (num & 1) == 1 {
			ans++
		}
		num >>= 1
	}
	return ans
}
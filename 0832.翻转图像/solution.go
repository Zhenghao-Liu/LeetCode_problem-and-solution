func flipAndInvertImage(A [][]int) [][]int {
	for i := range A {
		l, r := 0, len(A[i])-1
		for l <= r {
			A[i][l], A[i][r] = A[i][r]^1, A[i][l]^1
			l++
			r--
		}
	}
	return A
}

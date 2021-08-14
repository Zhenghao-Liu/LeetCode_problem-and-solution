func numberOfWeeks(milestones []int) int64 {
	var sum, mx int64 = 0, 0
	for _, i := range milestones {
		ii := int64(i)
		sum += ii
		mx = max(mx, ii)
	}
	if mx > sum-mx {
		diff := sum - mx
		return diff*2 + 1
	}
	return sum
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}
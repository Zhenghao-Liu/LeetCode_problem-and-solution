func shipWithinDays(weights []int, D int) int {
	l, r := max(weights), sum(weights)
	for l < r {
		mid := l + (r-l)/2
		cur, cnt := 0, 1
		for _, i := range weights {
			if cur+i > mid {
				cur = i
				cnt++
			} else {
				cur += i
			}
		}
		if cnt <= D {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l
}

func max(weights []int) int {
	mx := 0
	for _, i := range weights {
		if i > mx {
			mx = i
		}
	}
	return mx
}

func sum(weights []int) int {
	sum := 0
	for _, i := range weights {
		sum += i
	}
	return sum
}
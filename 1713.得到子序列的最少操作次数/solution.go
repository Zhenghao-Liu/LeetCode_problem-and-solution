func minOperations(target []int, arr []int) int {
	sz := len(target)
	mp := make(map[int]int, sz)
	for i, v := range target {
		mp[v] = i
	}
	vec := make([]int, 0, sz)
	for _, i := range arr {
		var idx int
		var ok bool
		if idx, ok = mp[i]; !ok {
			continue
		}
		if p := sort.SearchInts(vec, idx); p == len(vec) {
			vec = append(vec, idx)
		} else {
			vec[p] = idx
		}
	}
	return sz - len(vec)
}
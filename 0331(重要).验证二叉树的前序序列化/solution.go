func isValidSerialization(preorder string) bool {
	sta := make([]int, 0)
	sta = append(sta, 1)
	sz := len(preorder)
	for i := 0; i < sz; i++ {
		if preorder[i] == ',' {
			continue
		} else if preorder[i] == '#' {
			if len(sta) == 0 {
				return false
			}
			sta[len(sta)-1] -= 1
			if sta[len(sta)-1] == 0 {
				sta = sta[:len(sta)-1]
			}
		} else {
			for i < sz && preorder[i] >= '0' && preorder[i] <= '9' {
				i++
			}
			i--
			if len(sta) == 0 {
				return false
			}
			sta[len(sta)-1] -= 1
			if sta[len(sta)-1] == 0 {
				sta = sta[:len(sta)-1]
			}
			sta = append(sta, 2)
		}
	}
	return len(sta) == 0
}

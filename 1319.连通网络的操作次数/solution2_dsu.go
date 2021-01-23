var parent []int
var rank []int

func initUf(n int) {
	parent = make([]int, n)
	for i := 0; i < n; i++ {
		parent[i] = i
	}
	rank = make([]int, n)
}

func findRoot(cur int) int {
	if parent[cur] != cur {
		root := findRoot(parent[cur])
		parent[cur] = root
		return root
	}
	return cur
}

func unionVertices(a, b int) bool {
	aRoot := findRoot(a)
	bRoot := findRoot(b)
	if aRoot == bRoot {
		return false
	}
	if rank[aRoot] < rank[bRoot] {
		parent[aRoot] = bRoot
	} else {
		parent[bRoot] = aRoot
		if rank[aRoot] == rank[bRoot] {
			rank[aRoot]++
		}
	}
	return true
}
func makeConnected(n int, connections [][]int) int {
	var cnt int
	initUf(n)
	size := len(connections)
	for i := 0; i < size; i++ {
		if !unionVertices(connections[i][0], connections[i][1]) {
			cnt++
		}
	}
	var all int
	for i := 0; i < n; i++ {
		if findRoot(i) == i {
			all++
		}
	}
	all--
	if cnt >= all {
		return all
	}
	return -1
}

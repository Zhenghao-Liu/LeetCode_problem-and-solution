const MAXN = 1e4

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

func removeStones(stones [][]int) int {
	initUf(2*MAXN + 1)
	for _, i := range stones {
		x := i[0]
		y := i[1] + MAXN
		unionVertices(x, y)
	}
	mp := make(map[int]bool)
	for _, i := range stones {
		x := findRoot(i[0])
		mp[x] = true
		y := findRoot(i[1] + MAXN)
		mp[y] = true
	}
	return len(stones) - len(mp)
}

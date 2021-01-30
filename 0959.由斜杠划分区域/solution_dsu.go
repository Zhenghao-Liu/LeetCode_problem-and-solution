var parent []int
var rank []int
var cnt int

func initUf(n int) {
	parent = make([]int, n)
	for i := 0; i < n; i++ {
		parent[i] = i
	}
	rank = make([]int, n)
	cnt = n
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
	cnt--
	return true
}

func regionsBySlashes(grid []string) int {
	row := len(grid)
	col := len(grid[0])
	initUf(row * col * 4)
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			idx := (i*col + j) * 4
			if grid[i][j] == '/' {
				unionVertices(idx, idx+1)
				unionVertices(idx+2, idx+3)
			} else if grid[i][j] == '\\' {
				unionVertices(idx, idx+2)
				unionVertices(idx+1, idx+3)
			} else {
				unionVertices(idx, idx+1)
				unionVertices(idx+1, idx+2)
				unionVertices(idx+2, idx+3)
			}
			if i+1 < row {
				nxt := ((i+1)*col + j) * 4
				unionVertices(idx+3, nxt)
			}
			if j+1 < col {
				nxt := (i*col + j + 1) * 4
				unionVertices(idx+2, nxt+1)
			}
		}
	}
	return cnt
}

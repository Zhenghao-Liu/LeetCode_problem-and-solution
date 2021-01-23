var dx = [4]int{-1, 1, 0, 0}
var dy = [4]int{0, 0, -1, 1}
var parent []int
var rank []int
var cnt []int

func initUf(n int) {
	parent = make([]int, n)
    cnt = make([]int, n)
	for i := 0; i < n; i++ {
		parent[i] = i
        cnt[i] = 1
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
		cnt[bRoot] += cnt[aRoot]
	} else {
		parent[bRoot] = aRoot
		cnt[aRoot] += cnt[bRoot]
		if rank[aRoot] == rank[bRoot] {
			rank[aRoot]++
		}
	}
	return true
}

func size(a int) int {
	return cnt[findRoot(a)]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func hitBricks(grid [][]int, hits [][]int) []int {
	row := len(grid)
	col := len(grid[0])
	topRoot := row * col
	initUf(topRoot + 1)
	for _, i := range hits {
		x := i[0]
		y := i[1]
		if grid[x][y] == 1 {
			grid[x][y] = -1
		}
	}
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if grid[i][j] == 1 {
				cur := i*col + j
				if i == 0 {
					unionVertices(cur, topRoot)
				} else {
					if i-1 >= 0 && grid[i-1][j] == 1 {
						unionVertices(cur, (i-1)*col+j)
					}
					if j-1 >= 0 && grid[i][j-1] == 1 {
						unionVertices(cur, i*col+(j-1))
					}
				}
			}
		}
	}
	hits_size := len(hits)
	ans := make([]int, hits_size)
	for i := hits_size - 1; i >= 0; i-- {
		x := hits[i][0]
		y := hits[i][1]
		if grid[x][y] == 0 {
			continue
		}
		grid[x][y] = 1
		cur := x*col + y
		preCnt := size(topRoot)
        if x == 0 {
            unionVertices(cur, topRoot)
        }
		for j := 0; j < 4; j++ {
			xx := x + dx[j]
			yy := y + dy[j]
			if !(xx >= 0 && xx < row && yy >= 0 && yy < col) {
				continue
			}
			if grid[xx][yy] != 1 {
				continue
			}
			nxt := xx*col + yy
			unionVertices(cur, nxt)
		}
		curCnt := size(topRoot)
		ans[i] = max(0, curCnt-preCnt-1)
	}
	return ans
}

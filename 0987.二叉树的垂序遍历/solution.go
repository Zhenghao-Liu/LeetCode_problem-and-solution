/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func verticalTraversal(root *TreeNode) [][]int {
	type node struct {
		val, x, y int
	}
	vec := make([]node, 0)
	var dfs func(*TreeNode, int, int)
	dfs = func(root *TreeNode, x, y int) {
		if root == nil {
			return
		}
		vec = append(vec, node{root.Val, x, y})
		if root.Left != nil {
			dfs(root.Left, x+1, y-1)
		}
		if root.Right != nil {
			dfs(root.Right, x+1, y+1)
		}
	}
	dfs(root, 0, 0)
	sort.Slice(vec, func(a, b int) bool {
		return (vec[a].y < vec[b].y) ||
			(vec[a].y == vec[b].y && vec[a].x < vec[b].x) ||
			(vec[a].y == vec[b].y && vec[a].x == vec[b].x && vec[a].val < vec[b].val)
	})
	ans := make([][]int, 0)
	lst := math.MinInt32 / 2
	for _, i := range vec {
		val, y := i.val, i.y
		if y != lst {
			ans = append(ans, nil)
		}
		ans[len(ans)-1] = append(ans[len(ans)-1], val)
		lst = y
	}
	return ans
}

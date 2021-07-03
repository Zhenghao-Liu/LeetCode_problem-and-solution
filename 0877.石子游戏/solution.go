func stoneGame(piles []int) bool {
	sz := len(piles)
	dp := make([][]int, sz)
	for i := range dp {
		dp[i] = make([]int, sz)
		for j := range dp[i] {
			dp[i][j] = math.MinInt32 / 2
		}
		dp[i][i] = piles[i]
	}
	return dfs(dp, piles, 0, sz-1) > 0
}

func dfs(dp [][]int, piles []int, st, ed int) int {
	if dp[st][ed] != math.MinInt32/2 {
		return dp[st][ed]
	}
	dp[st][ed] = max(
		piles[st]-dfs(dp, piles, st+1, ed),
		piles[ed]-dfs(dp, piles, st, ed-1),
	)
	return dp[st][ed]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
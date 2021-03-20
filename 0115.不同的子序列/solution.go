func numDistinct(s string, t string) int {
    if s==t {
        return 1
    }
    szS,szT:=len(s),len(t)
    if szS<szT || szS==0 || szT==0 {
        return 0
    }
    dp:=make([][]int,szT)
    for i:=0;i<szT;i++ {
        dp[i]=make([]int,szS)
    }
    if s[0]==t[0] {
        dp[0][0]=1
    }
    for j:=1;j<szS;j++ {
        dp[0][j]=dp[0][j-1]
        if s[j]==t[0] {
            dp[0][j]++
        }
    }
    for i:=1;i<szT;i++ {
        for j:=i;j<szS;j++ {
            if t[i]==s[j] {
                dp[i][j]=dp[i-1][j-1]+dp[i][j-1]
            } else {
                dp[i][j]=dp[i][j-1]
            }
        }
    }
    return dp[szT-1][szS-1]
}

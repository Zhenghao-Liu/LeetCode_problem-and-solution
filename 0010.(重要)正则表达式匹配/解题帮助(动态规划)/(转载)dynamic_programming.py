"""
转载自
知乎用户 九四干
LeetCode用户 powcai
"""

"""
直接上动态方程:
p[j] == s[i]:dp[i][j] = dp[i-1][j-1]
p[j] == ".":dp[i][j] = dp[i-1][j-1]
p[j] =="*":
3.1 p[j-1] != s[i]:dp[i][j] = dp[i][j-2]
3.2 p[i-1] == s[i] or p[i-1] == ".":
dp[i][j] = dp[i-1][j] // 多个a的情况
or dp[i][j] = dp[i][j-1] // 单个a的情况，这里我想的是dp[i][j]=dp[i-1][j-2]，答案都对
or dp[i][j] = dp[i][j-2] // 没有a的情况
"""

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        #if not s or not p:
            #return False
        s_len = len(s)
        p_len = len(p)
        dp = [[False] * (p_len + 1) for _ in range(s_len + 1)]
        #print(dp)
        dp[0][0] = True
        for i in range(p_len):
            if p[i] == "*" and dp[0][i - 1]:
                dp[0][i + 1] = True
        #print(dp)
        for i in range(s_len):
            for j in range(p_len):
                if p[j] == s[i] or p[j] == ".":
                    dp[i + 1][j + 1] = dp[i][j]
                elif p[j] == "*":
                    if p[j - 1] != s[i]:
                        dp[i + 1][j + 1] = dp[i + 1][j - 1]
                    if p[j-1] == s[i] or p[j-1] == ".":
                        dp[i+1][j+1] = (dp[i][j+1] or dp[i+1][j]   or  dp[i+1][j-1])
        #print(dp)
        return dp[-1][-1]

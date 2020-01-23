//只适合于python，测试案例量比49题要大很多
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
            return False
        size=len(s)
        key=[2,3,5,7,11,13,
            17,19,23,29,31,37,
            41,43,47,53,59,61,
            67,71,73,79,83,89,
            97,101]
        a=b=1
        for i in range(0,len(s)):
            a=a*key[ord(s[i])-ord('a')]
            b=b*key[ord(t[i])-ord('a')]
        return a==b

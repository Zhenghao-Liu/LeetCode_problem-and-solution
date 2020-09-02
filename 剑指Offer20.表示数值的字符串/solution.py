class Solution:
    def isNumber(self, s: str) -> bool:
        try:
            answer=float(s)
            return True
        except:
            return False

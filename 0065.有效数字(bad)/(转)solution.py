class Solution(object):
    def isNumber(self, s):
        try:
            answer=float(s)
            return True
        except:
            return False

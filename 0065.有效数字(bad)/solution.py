class Solution(object):
    def isNumber(self, s):
        vec=["inf","-inf","+inf","Infinity","-Infinity","+Infinity"]
        if s in vec:
            return False
        try:
            answer=float(s)
            return True
        except:
            return False
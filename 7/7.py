class Solution:
    def reverse(self, x: int) -> int:
        ans = int(str(abs(x))[::-1]) * (1 if x>=0 else -1) 
        if ans < -2**31 or ans > 2**31-1:
            return 0
        else:
            return  ans
        

import math


class Solution:
    def reverse(self, x: int) -> int:
        if x==0 or x==1:
            return x
        digits = math.floor(math.log(abs(x), 10)+1)
        rx = 0
        a = -1 if x < 0 else 1
        x = abs(x)
        for i in range(digits):
            rx *= 10
            rx += x % 10
            x = int(x/10)

        return rx*a if (-2**31 <= rx <= 2**31-1) else 0

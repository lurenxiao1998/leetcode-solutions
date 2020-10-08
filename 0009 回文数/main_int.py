class Solution:
    def isPalindrome(self, x: int) -> bool:
        if(x < 0):
            return False
        cx = 0
        x_copy = x
        while(x_copy != 0):
            cx *= 10
            cx += x_copy % 10
            x_copy //= 10
        return True if x_copy == cx else False
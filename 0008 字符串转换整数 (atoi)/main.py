class Solution:
    def myAtoi(self, s: str) -> int:
        num = 0
        a = False
        Pos = True
        for i in range(len(s)):
            c = s[i]
            if(c != " "):
                if(ord("0") <= ord(c) <= ord("9")):
                    if(not a):
                        Pos = False if (i != 0 and s[i-1] == "-") else True
                    num *= 10
                    num += int(c)
                    a = True
                else:
                    if(not a):
                        if(c == "+"):
                            Pos = True
                            a=True
                        elif(c == "-"):
                            Pos = False
                            a=True
                        else:
                            num = num if Pos else -num
                            if(Pos):
                                return 2**31-1 if num > 2**31-1 else num
                            else:
                                return -2**31 if num < -2**31 else num
                    else:
                        num = num if Pos else -num
                        if(Pos):
                            return 2**31-1 if num > 2**31-1 else num
                        else:
                            return -2**31 if num < -2**31 else num
            else:
                if(a):
                    num = num if Pos else -num
                    if(Pos):
                        return 2**31-1 if num > 2**31-1 else num
                    else:
                        return -2**31 if num < -2**31 else num
        num = num if Pos else -num
        if(Pos):
            return 2**31-1 if num > 2**31-1 else num
        else:
            return -2**31 if num < -2**31 else num
        


a = Solution()
print(a.myAtoi("982"))

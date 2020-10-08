class Solution:
    def convert(self, s: str, numRows: int) -> str:
        floor = 1
        idx = 0
        cs = ""
        single = True
        i=0

        if(numRows==1):
            return s
        while i <len(s):
            i+=1
            if(idx < len(s)):
                # print(floor,idx,len(s),cs)
                if(floor == 1 or floor == numRows):
                    cs += s[idx]
                    idx += 2*numRows - 2
                else:
                    cs += s[idx]
                    if(single):
                        idx += 2*(numRows-floor)
                    else:
                        idx += 2*floor - 2
                    single = not single
            else:
                single = True
                idx = floor
                floor += 1
                i = i - 1
                # print(i)
        return cs
a=Solution()
print(a.convert("AB",1))

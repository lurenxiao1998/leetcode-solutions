class Solution:
    def longestPalindrome(self, s: str) -> str:
        l = ""
        # lookBack = False
        # idx = 0
        maxL = ""
        for i in range(len(s)-1):
            l+=s[i]
            # print(l)
            if(len(l) >= 1 and s[i+1] == l[len(l)-1]):
                tmp = ""
                for j in range(1, max(min(len(s)-len(l)+1, len(l)+1), 0)):
                    if(l[len(l)-j] == s[i+j]):
                        tmp = l[len(l)-j] + tmp +s[i+j]
                        # tmp.append()
                    else:
                        break
                if(len(tmp) > len(maxL)):
                    # print(l,tmp)
                    maxL = tmp
            if(len(l) >= 2 and s[i+1] == l[len(l)-2]):
                tmp = l[len(l)-1]
                for j in range(1, max(min(len(l), len(s)-len(l)+1), 0)):
                    if(l[len(l)-j-1] == s[i+j]):
                        tmp = l[len(l)-j-1]+tmp+ s[i+j]
                        # tmp.insert(0, l[len(l)-j])
                        # tmp.append(s[i+j])
                    else:
                        break
                if(len(tmp) > len(maxL)):
                    # print(l,tmp)
                    maxL = tmp
        if(len(maxL)==0):
            maxL = s[0]
        return maxL
a = Solution()
print(a.longestPalindrome("xaabacxcabaaxcabaax"))
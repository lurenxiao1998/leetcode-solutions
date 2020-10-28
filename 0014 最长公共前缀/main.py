class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        nl = 0
        flag = True
        LCP = ""
        if(len(strs) == 0):
            return LCP
        if(len(strs) == 1):
            return strs[0]
        for i in strs:
            if(i == ""):
                return ""
        while flag:
            if(nl == len(strs[0])):
                break
            tmp = strs[0][nl]
            for i in strs:
                if(nl == len(i)):
                    flag = False
                    break
                if(tmp != i[nl]):
                    flag = False
                    break
            if(flag == True):
                LCP += tmp
                nl += 1
        return LCP

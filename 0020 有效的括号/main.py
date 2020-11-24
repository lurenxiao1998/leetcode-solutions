class Solution:
    def isValid(self, s: str) -> bool:
        a=[]
        for i in s:
            if '['==i or '('==i or "{"==i:
                a.append(i)
            else:
                if len(a)==0:
                    return False
            if '}'==i:
                if a.pop() !="{":
                    return False
            
            if ')'==i:
                if a.pop() !="(":
                    return False
            
            if ']'==i:
                if a.pop() !="[":
                    return False
        return True and len(a)==0
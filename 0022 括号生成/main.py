class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if(n==0):
            return []
        rl=[]
        def recursive(lparentheseLeft,rparentheseLeft,s):
            if(lparentheseLeft==0):
                rl.append(s+rparentheseLeft*")")
                return
            if(rparentheseLeft>lparentheseLeft):
                recursive(lparentheseLeft-1,rparentheseLeft,s+'(')
                recursive(lparentheseLeft,rparentheseLeft-1,s+')')
            else:
                recursive(lparentheseLeft-1,rparentheseLeft,s+'(')
        recursive(n,n,'')
        return rl
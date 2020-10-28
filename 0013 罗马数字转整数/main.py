class Solution:
    def romanToInt(self, s: str) -> int:
        Romo ={"M": 1000, "D": 500, "C": 100,
                "L": 50, "X": 10, "V": 5, "I": 1}
        idx=0
        sum=0
        while(idx != len(s)):
            if(idx < len(s)-1 and Romo[s[idx]] <Romo[s[idx+1]] ):
                sum += Romo[s[idx+1]] - Romo[s[idx]]
                idx+=2
            else:
                sum += Romo[s[idx]]
                idx+=1
        return sum
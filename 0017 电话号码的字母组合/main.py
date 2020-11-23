class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        dict = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz"
        }
        if(digits==""):
            return []
        rl = []
        l = ['']
        for i in digits:
            for j in l:
                for k in dict[i]:
                    rl.append(j + k)
            l = rl
            rl = []
        return l

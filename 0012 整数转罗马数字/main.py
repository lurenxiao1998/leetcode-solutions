class Solution:
    def intToRoman(self, num: int) -> str:
        Romo = [("M", 1000), ("D", 500), ("C", 100),
                ("L", 50), ("X", 10), ("V", 5), ("I", 1)]
        s = ""
        for i in range(len(Romo)):
            times = num // Romo[i][1]
            print(Romo[i], times,num,s)
            s += times*Romo[i][0]
            num %= Romo[i][1]
            if(Romo[i][1] != 1):
                if(str(Romo[i][1])[0] == "1" and num//(Romo[i][1]*9//10) != 0):
                    print("2")
                    num -= Romo[i][1]*9//10
                    s += Romo[i+2][0] + Romo[i][0]
                elif(str(Romo[i][1])[0] == "5" and num//(Romo[i][1]*4//5) != 0):
                    print("1")
                    num -= Romo[i][1]*4//5
                    s += Romo[i+1][0] + Romo[i][0]
        return s


a = Solution()
print(a.intToRoman(58))

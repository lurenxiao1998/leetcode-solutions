from typing import List
class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        sequen=[]
        for i in range(len(nums)-1,-1,-1):
            if(len(sequen)<k):
                sequen.insert(0,nums[i])
            
            elif(nums[i]<sequen[0]):
                sequen.pop()
                sequen.insert(0,nums[i])
            elif(nums[i]==sequen[0]):
                for j in range(len(sequen)):
                    if(sequen[j]>nums[i]):
                        sequen.pop(j)
                        sequen.insert(0,nums[i])
                        break
        return sequen
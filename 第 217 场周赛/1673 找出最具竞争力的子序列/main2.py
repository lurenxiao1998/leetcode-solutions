from typing import List
class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        sequen=[]
        minidx=-1
        less=k
        length=len(nums)
        for i in range(k):
            number = min(nums[minidx+1:length-less+1])
            minidx=nums.index(number,minidx+1,length-less+1)
            sequen.append(nums[minidx])
            less-=1
        return sequen
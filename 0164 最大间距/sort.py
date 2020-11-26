class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        if(len(nums)<2):
            return 0
        nums.sort()
        maxMargin=0
        for i in range(1,len(nums)):
            if(nums[i]-nums[i-1]>maxMargin):
                maxMargin=nums[i]-nums[i-1]
        return maxMargin
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        for i in range(len(nums)):
            if(i!=0 and nums[i-1] == nums[i] ):
                continue

            while()
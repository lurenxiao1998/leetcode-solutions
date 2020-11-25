class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        a=[]
        length=len(nums)
        for i in range(length-1,-1,-1):
            if(nums[i]==val):
                nums.pop(i)
        return len(nums)
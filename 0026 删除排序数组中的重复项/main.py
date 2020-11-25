class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        count=0
        idx=1
        length = len(nums)
        while count < length-1:
            count +=1
            if(nums[idx]==nums[idx-1]):
                nums.pop(idx)
            else:
                idx+=1
        return len(nums)
from typing import List
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        tmpSet = []
        nums.sort()
        lasti = None
        for i in range(len(nums)-2):

            valuei = nums[i]
            if(lasti==nums[i]):
                continue

            li = i+1
            ri = len(nums)-1                

            while(li != ri):
                # print(nums, valuei,nums[li], nums[ri])
                if(0 == nums[li]+nums[ri]+valuei):
                    tmpSet.append([valuei, nums[li], nums[ri]])
                    ri -= 1
                elif(0 <= nums[li]+nums[ri]+valuei):
                    ri -= 1
                else:
                    li += 1
            lasti=nums[i]
        return tmpSet
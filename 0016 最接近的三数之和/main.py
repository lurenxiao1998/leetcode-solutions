from typing import List
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        ans = nums[0]+nums[1]+nums[2]
        for i in range(len(nums)-2):
            li = i+1
            ri = len(nums)-1
            while(li != ri):
                tmp = nums[li] + nums[ri]+nums[i]
                if(abs(tmp-target) < abs(ans-target)):
                    ans = tmp
                if(tmp-target < 0):
                    li += 1
                elif(tmp-target > 0):
                    ri -= 1
                else:
                    return ans
        return ans
a = Solution()
a.threeSumClosest([1, 2, 4, 8, 16, 32, 64, 128], 82)

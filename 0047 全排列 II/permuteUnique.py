from typing import List
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        # a = List[int]
        # b = List[int]
        self.vis = [False]*len(nums)
        # print(len(nums))
        nums.sort()
        ans=[]
        self.backtrack(nums,ans,0,[])
        return ans
        # for i in 
    def backtrack(self, nums: List[int], ans:List[List], idx:int, perm:List[int]):
        if(idx == len(nums)):
            ans.append(perm.copy())
            return

        for i in range(len(nums)):
            # print(i)
            # print(self.vis)
            if (self.vis[i] or (i>0 and nums[i-1] == nums[i] and not self.vis[i-1])) :
                continue
            perm.append(nums[i])
            self.vis[i]=True
            self.backtrack(nums,ans,idx+1,perm)
            self.vis[i]=False
            perm.pop()

a=Solution()
print(a.permuteUnique([1,1,2]))
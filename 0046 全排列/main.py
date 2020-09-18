class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        idx=0
        nums.sort()
        self.vis=[False]*len(nums)
        ans=[]
        self.backtrack(idx,nums,ans,[])
        return ans
    def backtrack(self,idx,nums,ans,perm):
        if(idx==len(nums)):
            ans.append(perm.copy())
        
        for i in range(len(nums)):
            if(self.vis[i]):
                continue
            
            perm.append(nums[i])
            self.vis[i]=True
            self.backtrack(idx+1,nums,ans,perm)
            self.vis[i]=False
            perm.pop()
        

        
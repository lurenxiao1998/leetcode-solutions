class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        eq = []
        i=0
        while(i<len(nums)-3):
            j=i+1
            while(j<len(nums)-2):
                li = j+1
                ri = len(nums)-1
                while li != ri:
                    if(nums[i]+nums[j]+nums[li]+nums[ri] == target):
                        eq.append([nums[i],nums[j],nums[li],nums[ri]])
                        while nums[ri]==nums[ri-1] and li!=ri-1:
                            ri-=1
                        ri-=1
                    elif(nums[i]+nums[j]+nums[li]+nums[ri] > target):
                        while nums[ri]==nums[ri-1] and li!=ri-1:
                            ri-=1
                        ri-=1
                    else:
                        while nums[li]==nums[li+1] and li+1!=ri:
                            li+=1
                        li+=1
                while j<=len(nums)-3 and nums[j]==nums[j+1]:
                    j+=1
                j+=1
            while i<=len(nums)-4 and nums[i]==nums[i+1]:
                i+=1
            i+=1
        return eq
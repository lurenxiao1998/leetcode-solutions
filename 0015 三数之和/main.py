from typing import List
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        tmpSet = []
        nums.sort()
        lasti = None
        lastj = None
        lastk= None
        for i in range(len(nums)-2):

            valuei = nums[i]
            if(lasti==nums[i]):
                continue

            li = i+1
            ri = len(nums)-1                

            lastj = None
            lastk= None
            while(li != ri):
                # print(nums, valuei,nums[li], nums[ri])
                j=nums[li]
                k=nums[ri]
                if(lastj==j):
                    li+=1
                    continue
                if(lastk==k):
                    ri-=1
                    continue
                if(0 == nums[li]+nums[ri]+valuei):
                    tmpSet.append([valuei, nums[li], nums[ri]])
                    lastk=k
                    ri -= 1
                elif(0 <= nums[li]+nums[ri]+valuei):
                    ri -= 1
                    lastk=k
                else:
                    li += 1
                    lastj=j
            lasti=nums[i]
        return tmpSet
a=[3,0,-2,-1,1,2]
b=Solution()
print(b.threeSum(a))

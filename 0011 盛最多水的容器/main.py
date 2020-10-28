class Solution:
    def maxArea(self, height: List[int]) -> int:
        li=0
        ri=len(height)-1
        maxWater=0
        while(li!=ri):
            width = ri-li
            deepth = min(height[li],height[ri])
            V = width*deepth
            if(V>maxWater):
                maxWater=V
            if(height[li]>height[ri]):
                ri-=1
            else:
                li+=1
        return maxWater

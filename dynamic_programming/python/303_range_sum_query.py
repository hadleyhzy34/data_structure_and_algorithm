class NumArray:

    def __init__(self, nums: List[int]):
       self.sum = []
       self.sum.append(nums[0])
       for i in range(1,len(nums)):
           self.sum.append(self.sum[i-1]+nums[i])

    def sumRange(self, left: int, right: int) -> int:
        if(left<1):
            return self.sum[right]
        else:
            return self.sum[right]-self.sum[left-1]



# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)

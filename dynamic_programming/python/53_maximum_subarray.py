# dp, to store max sum value that include current index element
def maxSubArray_v3(nums:list[int])->int:
    dp = []
    res = nums[0]

    dp.append(nums[0])
    for i in range(1,len(nums)):
        dp.append(max(dp[i-1]+nums[i],nums[i]))
        res = max(res,dp[i])
    return res

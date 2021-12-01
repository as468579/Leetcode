class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 1: return nums[0]
        elif len(nums) == 2: return max(nums[0], nums[1])
        
        dp = [0 for _ in nums]
        maximum = 0
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])
        for i in range(2, len(nums)):
            dp[i]   = max((nums[i] + dp[i-2]), dp[i-1])
            maximum = max(maximum, dp[i]) 

        return maximum

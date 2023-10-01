#
# @lc app=leetcode id=1480 lang=python
#
# [1480] Running Sum of 1d Array
#

# @lc code=start
class Solution(object):
    def runningSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        sum=0
        runsum=[]
        for i in range(len(nums)):
            for j in range(i+1):
                sum=sum+nums[j]
            runsum.append(sum)
            sum=0
        return runsum

Solution().runningSum([1,2,3,4])
# @lc code=end


#
# @lc app=leetcode id=1 lang=python
#
# [1] Two Sum
#

# @lc code=start
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        result = []
        n = len(nums)

        for i in range(n):
            for j in range(i+1,n):
                sum = nums[i] + nums[j]
                if sum==target:
                    a=i
                    b=j
        result.append(a)
        result.append(b)
        
        return result
        
# @lc code=end


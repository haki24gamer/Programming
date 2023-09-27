#Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
"""
run through the array nums, and add the the numbers together until finding a result equivalent to the target
"""
class Solution(object):
    def twoSum():
        nums = [3,3]
        target = 6
        n = len(nums)


        for i in range(n):
            for j in range(i+1,n):
                sum = nums[i] + nums[j]
                if sum==target:
                    a=i
                    b=j
        
        print("[",a,",",b,"]")
Solution.twoSum()


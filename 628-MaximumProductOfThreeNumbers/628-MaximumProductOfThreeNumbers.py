# Last updated: 10/03/2026, 13:44:51
class Solution:
    def maximumProduct(self, nums):
        nums.sort()
        n = len(nums)

        p1 = nums[n-1] * nums[n-2] * nums[n-3]

        p2 = nums[0] * nums [1] * nums[n-1]

        return max(p1, p2)
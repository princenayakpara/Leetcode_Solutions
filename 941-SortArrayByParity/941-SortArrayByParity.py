# Last updated: 10/03/2026, 13:44:47
class Solution(object):
    def sortArrayByParity(self, nums):
        j = 0

        for i in range(len(nums)):
            if nums[i]%2 == 0:
                nums[i], nums[j] = nums[j], nums[i]
                j+= 1

        return nums
        
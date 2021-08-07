
# LeetCode 剑指 Offer 51
# 逆序对

class Solution(object):
    def reversePairs(self, nums) -> int:
        n = len(nums)
        if n < 2:
            return 0
        copy = nums.copy()
        temp = [0] * n
        return self.findReversePairs(copy, 0, n - 1, temp)

    def findReversePairs(self, nums, left, right, temp) -> int:
        if left == right:
            return 0
        mid = left + (right - left) // 2
        leftPairs = self.findReversePairs(nums, left, mid, temp)
        rightPairs = self.findReversePairs(nums, mid + 1, right, temp)
        if nums[mid] <= nums[mid + 1]:
            return leftPairs + rightPairs

        crossPairs = self.mergeAndCount(nums, left, mid, right, temp)
        return leftPairs + rightPairs + crossPairs

    def mergeAndCount(self, nums, left, mid, right, temp) -> int:
        for i in range(left, right + 1):
            temp[i] = nums[i]
        i = left
        j = mid + 1
        count = 0
        for k in range(left, right + 1):
            if i == mid + 1:
                nums[k] = temp[j]
                j += 1
            elif j == right + 1:
                nums[k] = temp[i]
                i += 1
            elif temp[i] <= temp[j]:
                nums[k] = temp[i]
                i += 1
            else:
                nums[k] = temp[j]
                j += 1
                count += (mid - i + 1)
        return count

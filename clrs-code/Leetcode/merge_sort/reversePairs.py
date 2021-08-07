
# LeetCode 493
# 翻转对
# for any (i, j), hold i < j
# count the number of nums[i] > 2 * nums[j]

class Solution:
    def reversePairs(self, nums) -> int:
        n = len(nums)
        if n < 2:
            return 0
        temp = [0] * n
        return self.mergeSort(nums, 0, n - 1, temp)

    def mergeSort(self, nums, left, right, temp):
        if left == right:
            return 0
        else:
            mid = (left + right) // 2
            n1 = self.mergeSort(nums, left, mid, temp)
            n2 = self.mergeSort(nums, mid + 1, right, temp)
            ret = n1 + n2
            i = left
            j = mid + 1
            # 这里的时间复杂度不是 O(N^2)
            # 其实是 O(N)
            # 因为 j 的值不回溯
            # i 和 j 最坏情况下走完整个数组
            # 第二个 while 循环后有退出条件
            while i <= mid:
                while j <= right and nums[i] > 2 * nums[j]:
                    j += 1
                ret += (j - mid - 1)
                i += 1

            for i in range(left, right + 1):
                temp[i] = nums[i]

            i = left
            j = mid + 1
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

            return ret


nums = [8, 12, 14, 1, 2, 3]
count = Solution().reversePairs(nums)
print(count)


# LeetCode 912
# 归并排序

class Solution:
    def sortArray(self, nums):
        n = len(nums)
        if n < 2:
            return nums
        # 对 nums 进行排序，使用 temp 临时数组来“比较”
        temp = [0] * n
        # 对 nums[0..n-1] | nums[0..n) 进行排序
        return self.mergeSort(nums, 0, n - 1, temp)
    
    def mergeSort(self, nums, left, right, temp):
        if left == right:
            return nums
        mid = left + (right - left) // 2
        self.mergeSort(nums, left, mid, temp)
        self.mergeSort(nums, mid + 1, right, temp)
        # 优化，若合并之前已经是有序数组便可直接返回
        if nums[mid] <= nums[mid + 1]:
            return nums
        return self.merge(nums, left, mid, right, temp)

    def merge(self, nums, left, mid, right, temp):
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
            # 此处判断条件 <= 是一个稳定排序
            elif temp[i] <= temp[j]:
                nums[k] = temp[i]
                i += 1
            else:
                nums[k] = temp[j]
                j += 1
        return nums


nums = [3, 5, 1, 9, 7, 6, 4, 10, 2, 8]
sorted = Solution().sortArray(nums)
print(sorted)

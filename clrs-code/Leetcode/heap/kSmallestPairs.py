import heapq

class Solution:
    def kSmallestPairs(self, nums1, nums2, k: int):
        heap = []
        for n1 in nums1:
            for n2 in nums2:
                if len(heap) < k:
                    heapq.heappush(heap, (-n1-n2, [n1, n2]))
                elif heap and -heap[0][0] > n1 + n2:
                    heapq.heappop(heap)
                    heapq.heappush(heap, (-n1-n2, [n1, n2]))
                else:
                    break
        return [x[1] for x in heap if heap]

nums1 = [1,7,11]
nums2 = [2,4,6]
k = 3
res = Solution().kSmallestPairs(nums1, nums2 ,k)
print(res)

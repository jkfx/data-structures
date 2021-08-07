
# LeetCode 347

class Solution:

    def heapify(self, heap, n):
        for i in range(n // 2, -1, -1):
            self.maxheapify(heap, i, n)
    
    def maxheapify(self, heap, i, n):
        l = 2 * i + 1
        r = 2 * i + 2
        maxi = i
        if l < n and heap[l][1] > heap[maxi][1]:
            maxi = l
        if r < n and heap[r][1] > heap[maxi][1]:
            maxi = r
        if i != maxi:
            heap[i], heap[maxi] = heap[maxi], heap[i]
            self.maxheapify(heap, maxi, n)
    
    def heappop(self, heap, n):
        maxe = heap[0]
        heap[0] = heap[n - 1]
        self.maxheapify(heap, 0, n - 1)
        return maxe[0]

    def topKFrequent(self, nums, k: int):
        hmap = {}
        for elem in nums:
            if elem in hmap:
                hmap[elem] += 1
            else:
                hmap[elem] = 1
        items = hmap.items()
        heap = list(items)
        n = len(heap)
        self.heapify(heap, n)
        l = list()
        for i in range(k):
            l.append(self.heappop(heap, n))
            n -= 1
        return l


nums = [3,3,3,1,1,1,1,1,1,4,4,4,4,3,3,2,6,7,8,]
k = 3
print(Solution().topKFrequent(nums, k))
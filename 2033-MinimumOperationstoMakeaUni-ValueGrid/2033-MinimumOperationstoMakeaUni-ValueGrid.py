# Last updated: 3/26/2025, 9:44:31 AM
class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        # Flatten matrix and put into dict
        c = Counter(v for row in grid for v in row)

        # Find median value
        t =  1 + len(grid) * len(grid[0]) // 2
        current = 0
        for k in sorted(c):
            current += c[k]
            if current >=  t:
                target = k
                break

        # Walk through dict and add difference between values and median.
        m = grid[0][0] % x
        answer = 0
        for k, v in c.items():
            if k % x != m:
                return -1
            answer += abs(v * (k-target) // x)
        return answer
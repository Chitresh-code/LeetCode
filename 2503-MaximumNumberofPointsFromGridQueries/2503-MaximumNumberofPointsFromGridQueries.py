# Last updated: 3/28/2025, 2:17:57 PM
import heapq

class Solution:
    def maxPoints(self, grid: List[List[int]], queries: List[int]) -> List[int]:
        directions = [(0,1), (0,-1), (1,0), (-1,0)]
        rows, cols = len(grid), len(grid[0])
        
        # Min-Heap (priority queue)
        min_heap = [(grid[0][0], 0, 0)]  # (value, x, y)
        visited = [[False] * cols for _ in range(rows)]
        visited[0][0] = True  # Mark the starting cell as visited

        sorted_queries = sorted(queries)  # Sort queries for efficient processing
        query_results = {}
        
        points = 0  # Running total of reachable points
        
        for k in sorted_queries:
            while min_heap and min_heap[0][0] < k:
                value, x, y = heapq.heappop(min_heap)
                points += 1  # This cell is now counted as reachable
                
                for dx, dy in directions:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < rows and 0 <= ny < cols and not visited[nx][ny]:
                        visited[nx][ny] = True  # Mark before pushing to avoid duplicates
                        heapq.heappush(min_heap, (grid[nx][ny], nx, ny))

            query_results[k] = points  # Store the result for this threshold
        
        # Retrieve results in the original order of queries
        return [query_results[k] for k in queries]
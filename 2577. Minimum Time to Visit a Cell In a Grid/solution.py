from heapq import heappush, heappop

class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        
        # Early return if the second cell is blocked initially
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1
        
        # Priority queue for Dijkstra's algorithm
        pq = [(0, 0, 0)]  # (time, row, col)
        visited = set()
        
        while pq:
            time, r, c = heappop(pq)
            
            # If we've reached the bottom-right corner
            if (r, c) == (m - 1, n - 1):
                return time
            
            if (r, c) in visited:
                continue
            visited.add((r, c))
            
            # Explore neighbors
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n and (nr, nc) not in visited:
                    next_time = time + 1
                    if next_time < grid[nr][nc]:
                        # Wait until the constraint is met
                        wait_time = grid[nr][nc] - next_time
                        # Adjust wait time to align with even/odd constraints
                        if wait_time % 2 != 0:
                            wait_time += 1
                        next_time += wait_time
                    heappush(pq, (next_time, nr, nc))
        
        return -1

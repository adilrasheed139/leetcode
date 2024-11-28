from collections import deque

class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # right, down, left, up
        deque_queue = deque([(0, 0, 0)])  # (cost, row, col)
        visited = [[False] * n for _ in range(m)]
        
        while deque_queue:
            cost, x, y = deque_queue.popleft()
            
            # If we've reached the bottom-right corner, return the cost
            if x == m - 1 and y == n - 1:
                return cost
            
            # Mark as visited
            if visited[x][y]:
                continue
            visited[x][y] = True
            
            # Explore neighbors
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n and not visited[nx][ny]:
                    if grid[nx][ny] == 0:
                        deque_queue.appendleft((cost, nx, ny))  # Empty cell, prioritize
                    else:
                        deque_queue.append((cost + 1, nx, ny))  # Obstacle, add to the back
        
        return -1  # Should never reach here for valid input

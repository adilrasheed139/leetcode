from typing import List

class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        # Convert guards and walls into sets for quick access
        guard_set = set((r, c) for r, c in guards)
        wall_set = set((r, c) for r, c in walls)
        guarded_set = set()  # To track guarded cells

        # Directions for north, south, west, east
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        # Traverse each guard and mark cells they can guard
        for r, c in guards:
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                while 0 <= nr < m and 0 <= nc < n and (nr, nc) not in guard_set and (nr, nc) not in wall_set:
                    guarded_set.add((nr, nc))
                    nr, nc = nr + dr, nc + dc

        # Total cells - guards - walls - guarded cells = unguarded cells
        total_cells = m * n
        unguarded_cells = total_cells - len(guard_set) - len(wall_set) - len(guarded_set)

        return unguarded_cells

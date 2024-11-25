from collections import deque

class Solution:
    def slidingPuzzle(self, board: list[list[int]]) -> int:
        # Target state for the puzzle
        target = "123450"
        
        # Convert the 2D board to a string representation
        start = "".join(str(num) for row in board for num in row)
        
        # Possible moves for each index in the flattened board
        # Each index corresponds to where the `0` can move in a 2x3 grid
        moves = {
            0: [1, 3],       # 0 can move to 1 (right) or 3 (down)
            1: [0, 2, 4],    # 1 can move to 0 (left), 2 (right), or 4 (down)
            2: [1, 5],       # 2 can move to 1 (left) or 5 (down)
            3: [0, 4],       # 3 can move to 0 (up) or 4 (right)
            4: [1, 3, 5],    # 4 can move to 1 (up), 3 (left), or 5 (right)
            5: [2, 4]        # 5 can move to 2 (up) or 4 (left)
        }
        
        # BFS setup
        queue = deque([(start, start.index("0"), 0)])  # (current state, index of 0, steps)
        visited = set()
        visited.add(start)
        
        while queue:
            current, zero_index, steps = queue.popleft()
            
            # Check if we've reached the target
            if current == target:
                return steps
            
            # Explore all possible moves for the `0`
            for move in moves[zero_index]:
                # Swap `0` with the adjacent number
                new_board = list(current)
                new_board[zero_index], new_board[move] = new_board[move], new_board[zero_index]
                new_state = "".join(new_board)
                
                # Only process new states
                if new_state not in visited:
                    visited.add(new_state)
                    queue.append((new_state, move, steps + 1))
        
        # If the target state is not reachable
        return -1

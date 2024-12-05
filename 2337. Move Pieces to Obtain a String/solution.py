class Solution:
    def canChange(self, start: str, target: str) -> bool:
        # Remove all '_' and check if the remaining strings are identical
        if start.replace('_', '') != target.replace('_', ''):
            return False
        
        # Iterate through both strings and check positions of 'L' and 'R'
        start_pointer, target_pointer = 0, 0
        n = len(start)
        
        while start_pointer < n and target_pointer < n:
            # Skip blanks in start
            while start_pointer < n and start[start_pointer] == '_':
                start_pointer += 1
            
            # Skip blanks in target
            while target_pointer < n and target[target_pointer] == '_':
                target_pointer += 1
            
            # If both pointers are valid and pointing at pieces
            if start_pointer < n and target_pointer < n:
                if start[start_pointer] != target[target_pointer]:
                    return False  # Mismatch in pieces
                
                if start[start_pointer] == 'L' and start_pointer < target_pointer:
                    return False  # 'L' cannot move right
                
                if start[start_pointer] == 'R' and start_pointer > target_pointer:
                    return False  # 'R' cannot move left
                
                # Move to the next piece
                start_pointer += 1
                target_pointer += 1
        
        # If any leftover pieces in start or target, check if they are all '_'
        while start_pointer < n:
            if start[start_pointer] != '_':
                return False
            start_pointer += 1
        
        while target_pointer < n:
            if target[target_pointer] != '_':
                return False
            target_pointer += 1
        
        return True

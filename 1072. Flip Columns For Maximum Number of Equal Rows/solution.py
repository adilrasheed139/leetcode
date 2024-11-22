from collections import defaultdict

class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        pattern_count = defaultdict(int)
        
        for row in matrix:
            # Create the normal row and the flipped row
            normal = tuple(row)
            flipped = tuple(1 - x for x in row)  # Flip the row
            
            # Increment the pattern counts
            pattern_count[normal] += 1
            pattern_count[flipped] += 1
        
        # Return the maximum count of any pattern
        return max(pattern_count.values())

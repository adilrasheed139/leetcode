class Solution:
    def findScore(self, nums: List[int]) -> int:
        # Pair each element with its index and sort by value
        indexed_nums = sorted((num, i) for i, num in enumerate(nums))
        marked = set()  # To track marked indices
        score = 0
        
        for num, idx in indexed_nums:
            if idx not in marked:  # If the current element is not marked
                score += num  # Add its value to the score
                # Mark the current index and its adjacent indices
                marked.add(idx)
                if idx > 0:  # Left adjacent
                    marked.add(idx - 1)
                if idx < len(nums) - 1:  # Right adjacent
                    marked.add(idx + 1)
        
        return score

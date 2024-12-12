import math
from heapq import heapify, heappush, heappop

class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        # Convert the list into a max-heap by negating the values
        max_heap = [-gift for gift in gifts]
        heapify(max_heap)  # Create a heap
        
        # Perform k operations
        for _ in range(k):
            # Extract the richest pile (maximum gifts)
            richest_pile = -heappop(max_heap)  # Negate to get the actual value
            # Compute the remaining gifts in the pile
            remaining_gifts = math.floor(math.sqrt(richest_pile))
            # Push the remaining gifts back into the heap
            heappush(max_heap, -remaining_gifts)
        
        # Sum up the remaining gifts in all piles
        return -sum(max_heap)  # Negate back to positive values

from bisect import bisect_right

class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        # Sort items based on price, and for the same price, sort by beauty descending
        items.sort(key=lambda x: (x[0], -x[1]))  
        
        # Precompute the maximum beauty for each price up to that point
        max_beauty = []
        current_max = 0
        for price, beauty in items:
            current_max = max(current_max, beauty)
            max_beauty.append((price, current_max))
        
        # For each query, find the largest price <= query and return the corresponding max beauty
        result = []
        for q in queries:
            idx = bisect_right(max_beauty, (q, float('inf'))) - 1  # Find the index of the last item with price <= query
            if idx == -1:
                result.append(0)
            else:
                result.append(max_beauty[idx][1])
        
        return result
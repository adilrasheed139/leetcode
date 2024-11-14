from typing import List

class Solution:
    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        # Helper function to check if a given max products per store (max_products) is feasible
        def canDistribute(max_products: int) -> bool:
            stores_needed = 0
            for quantity in quantities:
                stores_needed += (quantity + max_products - 1) // max_products
                if stores_needed > n:
                    return False
            return stores_needed <= n

        # Binary search for the minimum possible x (max products per store)
        left, right = 1, max(quantities)
        while left < right:
            mid = (left + right) // 2
            if canDistribute(mid):
                right = mid  # try to find a smaller feasible x
            else:
                left = mid + 1  # increase x since current mid is too small

        return left
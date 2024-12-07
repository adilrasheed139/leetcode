class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        def canAchieve(penalty: int) -> bool:
            operations = 0
            for num in nums:
                if num > penalty:
                    operations += (num - 1) // penalty
                if operations > maxOperations:
                    return False
            return True
        
        # Binary search bounds
        left, right = 1, max(nums)
        result = right
        
        while left <= right:
            mid = (left + right) // 2
            if canAchieve(mid):
                result = mid  # Update result if feasible
                right = mid - 1  # Try smaller penalties
            else:
                left = mid + 1  # Try larger penalties
        
        return result

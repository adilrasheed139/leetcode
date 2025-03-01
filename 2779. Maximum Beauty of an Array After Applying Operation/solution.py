class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        # Step 1: Sort the array to simplify range checking
        nums.sort()

        # Step 2: Sliding window to find the maximum beauty
        max_beauty = 0
        left = 0  # Start of the window
        
        for right in range(len(nums)):
            # Check if the range of the window is valid
            while nums[right] - nums[left] > 2 * k:
                left += 1
            # Update the maximum beauty
            max_beauty = max(max_beauty, right - left + 1)
        
        return max_beauty

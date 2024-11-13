import bisect

class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums = sorted(nums)
        overall_count = 0

        for i in range(len(nums)):
            min_p1 = bisect.bisect_left(nums, lower - nums[i], i + 1, len(nums))
            max_p2 = bisect.bisect_right(nums, upper - nums[i], i + 1, len(nums)) - 1
            
            if min_p1 <= max_p2:
                overall_count += (max_p2 - min_p1 + 1)
        
        return overall_count
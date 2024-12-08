from bisect import bisect_right

class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        # Step 1: Sort events by end time
        events.sort(key=lambda x: x[1])
        
        # Precompute prefix max values and end times
        max_values = [0]  # Initialize with 0 to represent no event
        end_times = [0]   # Initialize with 0 to align with max_values index
        
        max_value_so_far = 0
        for start, end, value in events:
            max_value_so_far = max(max_value_so_far, value)
            max_values.append(max_value_so_far)
            end_times.append(end)
        
        result = 0
        
        # Step 2: Iterate through each event and calculate the max sum
        for start, end, value in events:
            # Binary search to find the latest non-overlapping event
            idx = bisect_right(end_times, start - 1) - 1
            
            # Calculate max sum for this event
            current_max = value + (max_values[idx] if idx >= 0 else 0)
            result = max(result, current_max)
        
        return result

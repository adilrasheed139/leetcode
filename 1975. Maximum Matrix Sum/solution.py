class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        total_sum = 0
        min_abs = float('inf')  # Smallest absolute value in the matrix
        negative_count = 0  # Count of negative numbers

        for row in matrix:
            for value in row:
                total_sum += abs(value)  # Sum the absolute values
                if value < 0:
                    negative_count += 1  # Count negative numbers
                min_abs = min(min_abs, abs(value))  # Track smallest absolute value

        # If the count of negatives is odd, subtract twice the smallest absolute value
        if negative_count % 2 == 1:
            total_sum -= 2 * min_abs

        return total_sum

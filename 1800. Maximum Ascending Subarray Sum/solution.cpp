class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = nums[0];  // Maximum sum found so far
        int currentSum = nums[0];  // Current ascending subarray sum

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                currentSum += nums[i];  // Extend the ascending subarray
            } else {
                currentSum = nums[i];  // Start a new subarray
            }
            maxSum = max(maxSum, currentSum);  // Update the max sum
        }

        return maxSum;
    }
};

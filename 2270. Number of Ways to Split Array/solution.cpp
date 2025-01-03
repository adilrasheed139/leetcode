class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum = 0;
        for (int num : nums) {
            totalSum += num; // Calculate the total sum of the array
        }

        long long leftSum = 0;
        int validSplits = 0;
        int n = nums.size();

        for (int i = 0; i < n - 1; ++i) {
            leftSum += nums[i]; // Update the left sum
            long long rightSum = totalSum - leftSum; // Calculate the right sum
            if (leftSum >= rightSum) {
                validSplits++; // Increment count if the condition is satisfied
            }
        }

        return validSplits;
    }
};

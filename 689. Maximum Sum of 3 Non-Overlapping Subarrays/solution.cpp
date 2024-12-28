class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> windowSums(n - k + 1, 0);
        vector<int> left(n - k + 1, 0), right(n - k + 1, 0);
        vector<int> result(3, 0);

        // Step 1: Calculate sums of all windows of size k
        int currentSum = 0;
        for (int i = 0; i < n; ++i) {
            currentSum += nums[i];
            if (i >= k) currentSum -= nums[i - k];
            if (i >= k - 1) windowSums[i - k + 1] = currentSum;
        }

        // Step 2: Calculate the left max indices
        int maxIdx = 0;
        for (int i = 0; i < windowSums.size(); ++i) {
            if (windowSums[i] > windowSums[maxIdx]) maxIdx = i;
            left[i] = maxIdx;
        }

        // Step 3: Calculate the right max indices
        maxIdx = windowSums.size() - 1;
        for (int i = windowSums.size() - 1; i >= 0; --i) {
            if (windowSums[i] >= windowSums[maxIdx]) maxIdx = i;
            right[i] = maxIdx;
        }

        // Step 4: Find the maximum sum using left, middle, and right
        int maxSum = 0;
        for (int middle = k; middle < windowSums.size() - k; ++middle) {
            int l = left[middle - k];
            int r = right[middle + k];
            int totalSum = windowSums[l] + windowSums[middle] + windowSums[r];
            if (totalSum > maxSum) {
                maxSum = totalSum;
                result = {l, middle, r};
            }
        }

        return result;
    }
};

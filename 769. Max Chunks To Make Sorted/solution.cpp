class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Create maxLeft and minRight arrays
        vector<int> maxLeft(n), minRight(n);
        
        // Fill maxLeft array (maximum element from left to right)
        maxLeft[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            maxLeft[i] = max(maxLeft[i - 1], arr[i]);
        }
        
        // Fill minRight array (minimum element from right to left)
        minRight[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            minRight[i] = min(minRight[i + 1], arr[i]);
        }
        
        // Step 2: Count valid chunks
        int chunks = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (maxLeft[i] <= minRight[i + 1]) {
                chunks++;
            }
        }
        
        // The last chunk is always valid, so we add 1 to chunks
        return chunks + 1;
    }
};

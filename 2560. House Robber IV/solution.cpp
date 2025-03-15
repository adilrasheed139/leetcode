class Solution {
    public:
        bool canRobWithCapability(vector<int>& nums, int k, int capability) {
            int count = 0;
            int n = nums.size();
            for (int i = 0; i < n; i++) {
                if (nums[i] <= capability) { 
                    count++;
                    i++; // Skip the next house since adjacent houses cannot be robbed
                }
            }
            return count >= k;
        }
    
        int minCapability(vector<int>& nums, int k) {
            int left = *min_element(nums.begin(), nums.end());
            int right = *max_element(nums.begin(), nums.end());
            int ans = right;
    
            while (left <= right) {
                int mid = left + (right - left) / 2;
    
                if (canRobWithCapability(nums, k, mid)) {
                    ans = mid;
                    right = mid - 1; // Try for a smaller capability
                } else {
                    left = mid + 1; // Increase capability
                }
            }
    
            return ans;
        }
    };
    
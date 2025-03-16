class Solution {
    public:
        long long repairCars(vector<int>& ranks, int cars) {
            long long left = 1, right = 1LL * *min_element(ranks.begin(), ranks.end()) * cars * cars;
            long long answer = right;
            
            while (left <= right) {
                long long mid = left + (right - left) / 2;
                
                // Count total cars that can be repaired within 'mid' minutes
                long long total_cars = 0;
                for (int rank : ranks) {
                    total_cars += sqrt(mid / rank); // Cars repaired by this mechanic
                    if (total_cars >= cars) break; // No need to check further
                }
    
                if (total_cars >= cars) {
                    answer = mid;
                    right = mid - 1; // Try to find a smaller time
                } else {
                    left = mid + 1; // Increase time
                }
            }
            
            return answer;
        }
    };
    
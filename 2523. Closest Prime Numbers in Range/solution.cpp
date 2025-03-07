class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            // Step 1: Generate primes using Sieve of Eratosthenes
            int limit = right + 1;  // Include `right` in our sieve
            vector<bool> is_prime(limit, true);
            is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime
            
            for (int i = 2; i * i < limit; ++i) {
                if (is_prime[i]) {
                    for (int j = i * i; j < limit; j += i) {
                        is_prime[j] = false;
                    }
                }
            }
    
            // Step 2: Collect primes in the given range
            vector<int> primes;
            for (int i = left; i <= right; ++i) {
                if (is_prime[i]) {
                    primes.push_back(i);
                }
            }
    
            // Step 3: Find the closest prime pair
            if (primes.size() < 2) {
                return {-1, -1};  // No valid pair found
            }
    
            int minDiff = INT_MAX;
            vector<int> result = {-1, -1};
    
            for (int i = 1; i < primes.size(); ++i) {
                int diff = primes[i] - primes[i - 1];
                if (diff < minDiff) {
                    minDiff = diff;
                    result = {primes[i - 1], primes[i]};
                }
            }
    
            return result;
        }
    };
    
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        // If k is greater than the length of the string, it's impossible
        if (k > s.length()) {
            return false;
        }
        
        // Count character frequencies
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        // Count characters with odd frequencies
        int oddCount = 0;
        for (auto& [char_, count] : freq) {
            if (count % 2 != 0) {
                oddCount++;
            }
        }
        
        // Check if the number of odd frequencies is less than or equal to k
        return oddCount <= k;
    }
};

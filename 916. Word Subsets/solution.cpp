#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // Step 1: Build the max frequency map for words2
        vector<int> maxFreq(26, 0);
        for (const string& b : words2) {
            vector<int> freq(26, 0);
            for (char c : b) {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }
        
        // Step 2: Find universal words in words1
        vector<string> result;
        for (const string& a : words1) {
            vector<int> freq(26, 0);
            for (char c : a) {
                freq[c - 'a']++;
            }
            bool isUniversal = true;
            for (int i = 0; i < 26; ++i) {
                if (freq[i] < maxFreq[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                result.push_back(a);
            }
        }
        
        return result;
    }
};

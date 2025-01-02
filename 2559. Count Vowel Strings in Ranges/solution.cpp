class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // Helper function to check if a string starts and ends with a vowel
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        // Step 1: Precompute prefix sums
        int n = words.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            if (isVowel(words[i].front()) && isVowel(words[i].back())) {
                prefix[i + 1] = prefix[i] + 1;
            } else {
                prefix[i + 1] = prefix[i];
            }
        }

        // Step 2: Process each query
        vector<int> ans;
        for (const auto& query : queries) {
            int l = query[0], r = query[1];
            ans.push_back(prefix[r + 1] - prefix[l]);
        }

        return ans;
    }
};

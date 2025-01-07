class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;
        int n = words.size();
        
        // Iterate over each word
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Skip comparing the word with itself
                if (i != j && words[j].find(words[i]) != string::npos) {
                    result.push_back(words[i]);
                    break; // No need to check further once we find a match
                }
            }
        }
        
        return result;
    }
};

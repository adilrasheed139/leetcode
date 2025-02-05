class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true; // If both strings are already equal, return true

        vector<int> diffIndices; // To store indices where characters differ

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                diffIndices.push_back(i);
            }
        }

        // If there are more than 2 differences, return false
        if (diffIndices.size() != 2) return false;

        // Swap the two differing indices in s1 and check if it matches s2
        int i = diffIndices[0], j = diffIndices[1];
        return (s1[i] == s2[j] && s1[j] == s2[i]);
    }
};

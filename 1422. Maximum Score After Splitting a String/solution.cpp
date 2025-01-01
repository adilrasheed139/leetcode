class Solution {
public:
    int maxScore(string s) {
        int totalOnes = 0;
        // Count total 1's in the string
        for (char c : s) {
            if (c == '1') totalOnes++;
        }

        int maxScore = 0;
        int leftZeros = 0;  // Number of zeros in the left substring
        int rightOnes = totalOnes; // Initially, all ones are on the right

        // Iterate through the string until the second-to-last character
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '0') leftZeros++;
            else rightOnes--;

            // Calculate the score at the current split
            int currentScore = leftZeros + rightOnes;
            maxScore = max(maxScore, currentScore);
        }

        return maxScore;
    }
};

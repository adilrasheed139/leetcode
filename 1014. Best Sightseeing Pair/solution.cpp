class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = 0;
        int maxLeft = values[0] + 0; // Initially, the best value of (values[i] + i)

        for (int j = 1; j < values.size(); ++j) {
            // Calculate the score for the current j
            maxScore = std::max(maxScore, maxLeft + values[j] - j);

            // Update maxLeft for the next iteration
            maxLeft = std::max(maxLeft, values[j] + j);
        }

        return maxScore;
    }
};

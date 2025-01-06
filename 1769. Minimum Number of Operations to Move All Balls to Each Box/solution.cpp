class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);

        // Left-to-right pass
        int leftBalls = 0, leftCost = 0;
        for (int i = 0; i < n; ++i) {
            answer[i] += leftCost;
            if (boxes[i] == '1') {
                ++leftBalls;
            }
            leftCost += leftBalls;
        }

        // Right-to-left pass
        int rightBalls = 0, rightCost = 0;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] += rightCost;
            if (boxes[i] == '1') {
                ++rightBalls;
            }
            rightCost += rightBalls;
        }

        return answer;
    }
};

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball_colors;  // Stores the current color of each ball
        unordered_map<int, int> color_count;  // Stores the count of each color
        unordered_set<int> unique_colors;     // Stores distinct colors
        vector<int> result;
        
        for (auto& query : queries) {
            int ball = query[0], color = query[1];

            // Check if the ball already has a color
            if (ball_colors.find(ball) != ball_colors.end()) {
                int old_color = ball_colors[ball];

                // Decrease the count of the old color
                if (--color_count[old_color] == 0) {
                    unique_colors.erase(old_color);
                }
            }

            // Assign new color to the ball
            ball_colors[ball] = color;
            color_count[color]++;
            unique_colors.insert(color);

            // Store the count of distinct colors
            result.push_back(unique_colors.size());
        }

        return result;
    }
};

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result(prices); // Initialize result with the original prices
        stack<int> st; // Stack to store indices
        
        for (int i = 0; i < n; ++i) {
            // While stack is not empty and the current price is <= price at top of the stack
            while (!st.empty() && prices[i] <= prices[st.top()]) {
                int idx = st.top();
                st.pop();
                result[idx] = prices[idx] - prices[i]; // Apply the discount
            }
            st.push(i); // Push current index onto the stack
        }
        
        return result;
    }
};

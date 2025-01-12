class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        // If the length of the string is odd, it's impossible to balance
        if (n % 2 != 0) return false;
        
        // Forward pass: Check for ')' not exceeding '('
        int open = 0, flexible = 0; // open: '(' count, flexible: unlocked count
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') {
                flexible++; // unlocked, can be used to balance
            } else if (s[i] == '(') {
                open++; // locked '('
            } else {
                if (open > 0) open--; // match locked ')'
                else if (flexible > 0) flexible--; // use flexible to balance ')'
                else return false; // unmatched ')'
            }
        }
        
        // Backward pass: Check for '(' not exceeding ')'
        int close = 0;
        flexible = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '0') {
                flexible++; // unlocked, can be used to balance
            } else if (s[i] == ')') {
                close++; // locked ')'
            } else {
                if (close > 0) close--; // match locked '('
                else if (flexible > 0) flexible--; // use flexible to balance '('
                else return false; // unmatched '('
            }
        }
        
        return true; // Passed both checks
    }
};

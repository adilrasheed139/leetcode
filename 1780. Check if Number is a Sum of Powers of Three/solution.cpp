class Solution {
    public:
        bool checkPowersOfThree(int n) {
            while (n > 0) {
                if (n % 3 == 2) return false; // If remainder is 2, return false
                n /= 3; // Move to the next power of three
            }
            return true; // If we only encountered 0s and 1s, return true
        }
    };
    
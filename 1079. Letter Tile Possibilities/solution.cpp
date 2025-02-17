class Solution {
    public:
        int count = 0;
        
        void backtrack(vector<int>& freq) {
            for (int i = 0; i < 26; i++) {
                if (freq[i] > 0) {
                    count++;  // Each new sequence formed
                    
                    freq[i]--;  // Use this character
                    backtrack(freq);  // Recur to explore further sequences
                    freq[i]++;  // Backtrack (undo choice)
                }
            }
        }
        
        int numTilePossibilities(string tiles) {
            vector<int> freq(26, 0);
            
            // Count frequency of each letter
            for (char c : tiles) {
                freq[c - 'A']++;
            }
            
            // Start backtracking
            backtrack(freq);
            
            return count;
        }
    };
    
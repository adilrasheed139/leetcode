#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1); // To store first occurrence of each character
        vector<int> last(26, -1);  // To store last occurrence of each character

        // Find first and last occurrences of each character
        for (int i = 0; i < s.size(); ++i) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }

        unordered_set<string> uniquePalindromes;

        // Check for palindromes
        for (int i = 0; i < 26; ++i) {
            if (first[i] != -1 && last[i] != -1 && first[i] < last[i]) {
                unordered_set<char> middleCharacters;
                // Collect unique characters in the middle substring
                for (int j = first[i] + 1; j < last[i]; ++j) {
                    middleCharacters.insert(s[j]);
                }
                // Add all palindromes to the set
                for (char midChar : middleCharacters) {
                    string palindrome = string(1, 'a' + i) + midChar + string(1, 'a' + i);
                    uniquePalindromes.insert(palindrome);
                }
            }
        }

        // The size of the set gives the count of unique palindromes
        return uniquePalindromes.size();
    }
};

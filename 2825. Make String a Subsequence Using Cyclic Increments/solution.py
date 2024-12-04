class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        # Pointers for str1 and str2
        i, j = 0, 0
        n, m = len(str1), len(str2)
        
        # Traverse both strings
        while i < n and j < m:
            # Check if current character matches directly
            # or matches after a cyclic increment
            if str1[i] == str2[j] or (ord(str1[i]) - ord('a') + 1) % 26 + ord('a') == ord(str2[j]):
                j += 1  # Move pointer in str2 if a match is found
            i += 1  # Always move pointer in str1
        
        # If we successfully traverse str2, it means it's a subsequence
        return j == m

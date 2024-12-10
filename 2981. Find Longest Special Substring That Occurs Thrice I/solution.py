class Solution:
    def maximumLength(self, s: str) -> int:
        n = len(s)
        
        # Iterate over possible substring lengths, starting from longest to shortest
        for length in range(n, 0, -1):
            count_map = {}
            
            # Check all substrings of the current length
            for i in range(n - length + 1):
                substring = s[i:i + length]
                
                # Check if the substring is "special"
                if len(set(substring)) == 1:  # All characters are the same
                    count_map[substring] = count_map.get(substring, 0) + 1
            
            # Check if any special substring occurs at least three times
            for key, count in count_map.items():
                if count >= 3:
                    return length
        
        # If no valid substring found, return -1
        return -1
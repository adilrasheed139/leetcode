class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        result = []
        prev_idx = 0
        
        # Add spaces at the specified indices
        for space in spaces:
            result.append(s[prev_idx:space])  # Add substring from previous index to current space index
            result.append(' ')  # Add the space
            prev_idx = space  # Update previous index to the current space position
        
        # Add the remaining part of the string after the last space
        result.append(s[prev_idx:])
        
        return ''.join(result)

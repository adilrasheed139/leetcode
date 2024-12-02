class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        # Split the sentence into words
        words = sentence.split()
        
        # Iterate through each word in the sentence with its index
        for index, word in enumerate(words):
            # Check if the searchWord is a prefix of the current word
            if word.startswith(searchWord):
                # Return the 1-indexed position of the word
                return index + 1
        
        # If no word matches, return -1
        return -1

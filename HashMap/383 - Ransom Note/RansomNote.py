class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        
        magDict = {}    # Create dict to store characters of magazine string

        # Store the characters of the magazine string
        for i in magazine:
            if (magDict.get(i) != None):
                # Increment Value of the key by 1 if present already
                magDict[i] += 1
            else:
                # Add a new key-value pair
                magDict[i] = 1
        

        # Checks if the characters in the note are present in the dict
        for j in ransomNote:
            if (magDict.get(j) != None):
                # if the character is present and their value is >1, then
                # decrement the value by 1
                if (magDict.get(j) > 1):
                    magDict[j] -= 1
                # If the character is present and their value is =1, then remove
                # the key-value pair from dict
                else:
                    # Pop the character. If the character is not present, then
                    # return None
                    magDict.pop(j, None)  
            # If character is not present then return False
            else:
                return False
        
        return True
        
# Alternate implementation below
"""
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        for letter in ransomNote:
            if magazine.find(letter) != -1:
                magazine = magazine.replace(letter, '', 1)
            else:
                return False

        return True
"""
    
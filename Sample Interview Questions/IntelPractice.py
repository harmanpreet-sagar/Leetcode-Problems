"""
Implement a function that given an integer array and its length, returns the
length of the longest sequence of alternating odd and even numbers. For
instance, in the array 112365546, it will return 5 (for the sequence 12365).
"""

class Solution:

    def maxLength(arr, size):
        
        maxLen = 0
        currentLen = 0

        for i in range(1, size):
            if (arr[i - 1] % 2 == 0):
                if (arr[i] % 2 != 0):
                    currentLen += 1
                else:
                    currentLen = 0
            else:
                if (arr[i] % 2 == 0):
                    currentLen += 1
                else:
                    currentLen = 0
            
            if ((currentLen + 1) > maxLen):
                maxLen = currentLen + 1     # The reason it is plus 1, because we need to account for the start.

        return maxLen
    
nums = [1,1,2,3,6,5,5,4,6]
size = len(nums)
print(Solution.maxLength(nums, size))
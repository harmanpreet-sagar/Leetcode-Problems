class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:

        k = 1

        for i in range(1, len(nums)):
            # Since the array is sorted, we only care if the previous number
            # matched this number. If it did, then we don't do anything.
            # However, if it doesn't then we put this number to be one of the
            # first numbers.
            if (nums[i] != nums[i - 1]):    
                nums[k] = nums[i]
                k += 1
        
        return k

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:

        k = 2

        check = nums[0] # Initializes a variable to be compared to

        for i in range(2, len(nums)):
            # Since the array is sorted, we only care if the number 2 places
            # before matched this number. If it did, then we don't do anything.
            # However, if it doesn't then we put this number to be one of the
            # first numbers.
            if (nums[i] != check):
                # Updates the comparison variable to the number before as for
                # the next run, the number to be compared against would be the
                # one before for this run.

                # This variable is created so that during list manipulation, the
                # value being compared against is the original value.
                check = nums[i - 1]    
                nums[k] = nums[i]
                k += 1
            else:
                check = nums[i - 1] 

        
        return k

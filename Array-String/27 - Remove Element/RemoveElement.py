class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:

        k = 0   # Stores the length of the list

        for i in range(len(nums)):
            if (nums[i] != val):
                # If the value of the current element is not equal to the value 
                # to be removed, replace the element at nums[k] with the current element
                nums[k] = nums[i]   
                k += 1
                
        return k


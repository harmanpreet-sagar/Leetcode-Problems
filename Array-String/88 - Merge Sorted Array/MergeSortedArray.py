class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """

        # Merge nums1 and nums2 into nums1
        nums1[m:m+n] = nums2    # extends nums1 to accommodate the elements from nums2
        nums1.sort()            # sort the list

        
    
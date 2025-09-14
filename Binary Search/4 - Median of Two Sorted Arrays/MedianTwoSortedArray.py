"""class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        
        if (len(nums1) > len(nums2)) :
            nums1, nums2 = nums2, nums1
        
        n = len(nums1)
        m = len(nums2)

        

        totalLength = n + m

        leftPtr = 0
        rightPtr = n - 1

        half = totalLength // 2

        while True:
            part1AIndex = (leftPtr + rightPtr) // 2
            part1BIndex = half - part1AIndex - 2    # We do -2 in order to make sure we take care of the offset of the index

            p1AFinalE = nums1[part1AIndex] if part1AIndex >= 0 else float("-infinity")
            p1BFinalE = nums2[part1BIndex] if part1BIndex >= 0 else float("-infinity")
            p2AFirstE = nums1[part1AIndex + 1] if part1AIndex + 1 < n else float("infinity")
            p2BFirstE = nums2[part1BIndex + 1] if part1BIndex + 1 < m else float("infinity")

            if p1AFinalE <= p2BFirstE and p1BFinalE <= p2AFirstE:
                # Found correct partition
                if totalLength % 2 == 0:
                    median = (max(p1AFinalE, p1BFinalE) + min(p2AFirstE, p2BFirstE)) / 2
                else:
                    median = min(p2AFirstE, p2BFirstE)
                return median
            elif p1AFinalE > p2BFirstE:
                rightPtr = part1AIndex - 1
            else:
                leftPtr = part1AIndex + 1

        return 0.0  # Handle the case if arrays are empty or other edge cases"""



class Solution:
    def findMedianSortedArrays(nums1, nums2) -> float:
        n = len(nums1)
        m = len(nums2)

        totalLength = n + m

        

        half = totalLength // 2

        if (nums1[n - 1] < nums2[0]):
            if n > m :
                return nums1[totalLength - half - 1]
            else:
                return nums2[m - half - 1]
        elif (nums2[m - 1] < nums1[0]):
            if n > m:
                return nums1[n - half - 1]
            else:
                return nums2[totalLength - half - 1]
        else:
            if (n > m) :
                leftPtr = 0
                rightPtr = m - 1
                while (leftPtr <= rightPtr):
                    maxLPartBIndex = (leftPtr + rightPtr) // 2 
                    # We do maxLPartAIndex - 1 because maxLPartAIndex starts at 0. At the
                    # end, we also subtract -1 because half begins with 0.
                    maxLPartAIndex = half - (maxLPartBIndex + 1) - 1

                    p1AFinalE = nums1[maxLPartAIndex]
                    p1BFinalE = nums2[maxLPartBIndex]
                    p2AFirstE = nums1[maxLPartAIndex + 1] if (maxLPartAIndex < n - 1) else (max(nums1[n - 1], nums2[m - 1]) + 1)
                    p2BFirstE = nums2[maxLPartBIndex + 1] if (maxLPartBIndex < m - 1) else (max(nums1[n - 1], nums2[m - 1]) + 1)

                    if (p1AFinalE <= p2BFirstE) and (p1BFinalE <= p2AFirstE):
                        return p2BFirstE
                    elif p1BFinalE > p2AFirstE:
                        rightPtr = maxLPartBIndex - 1
                    else:
                        leftPtr = maxLPartBIndex + 1
            else:
                leftPtr = 0
                rightPtr = n - 1
                while (leftPtr <= rightPtr):
                    maxLPartAIndex = (leftPtr + rightPtr) // 2
                    # We do maxLPartAIndex - 1 because maxLPartAIndex starts at 0. At the
                    # end, we also subtract -1 because half begins with 0.
                    maxLPartBIndex = half - (maxLPartAIndex + 1) - 1 # half - (maxLPartAIndex + 1) - 1

                    p1AFinalE = nums1[maxLPartAIndex]
                    p1BFinalE = nums2[maxLPartBIndex]
                    p2AFirstE = nums1[maxLPartAIndex + 1] if (maxLPartAIndex < n - 1) else (max(nums1[n - 1], nums2[m - 1]) + 1)
                    p2BFirstE = nums2[maxLPartBIndex + 1] if (maxLPartBIndex < m - 1) else (max(nums1[n - 1], nums2[m - 1]) + 1)

                    if p1AFinalE <= p2BFirstE and p1BFinalE <= p2AFirstE:
                        return p2AFirstE
                    elif p1AFinalE > p2BFirstE:
                        rightPtr = maxLPartAIndex - 1
                    else:
                        leftPtr = maxLPartAIndex + 1
        
        # If that didn't pan out then try this configuration.
        # return findMedianSortedArrays(nums2, nums1)
                
list1 = [1, 3, 5, 7, 9]
list2 = [2, 4, 6, 8, 10, 11]
print(Solution.findMedianSortedArrays(list1, list2))



"""
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        n = len(nums1)
        m = len(nums2)

        left = 0
        right = n

        while left <= right:
            partitionX = (left + right) // 2
            partitionY = (n + m + 1) // 2 - partitionX

            maxLeftX = float("-inf") if partitionX == 0 else nums1[partitionX - 1]
            minRightX = float("inf") if partitionX == n else nums1[partitionX]
            maxLeftY = float("-inf") if partitionY == 0 else nums2[partitionY - 1]
            minRightY = float("inf") if partitionY == m else nums2[partitionY]

            if maxLeftX <= minRightY and maxLeftY <= minRightX:
                if (n + m) % 2 == 0:
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2
                else:
                    return max(maxLeftX, maxLeftY)
            elif maxLeftX > minRightY:
                right = partitionX - 1
            else:
                left = partitionX + 1

        return 0.0

"""
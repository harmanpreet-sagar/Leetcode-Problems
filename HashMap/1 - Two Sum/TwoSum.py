class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numDict = {}
        size = len(nums)
            

        for j in range(size):
            val = target - nums[j]
            if ((val in numDict) and numDict.get(val) != j):
                return [j, numDict.get(val)]
            numDict[nums[j]] = j
            
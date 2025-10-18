class Solution:
    def countMatchingSubarrays(self, nums: list[int], pattern: list[int]) -> int:
        pat_length = len(pattern) + 1
        count = 0

        # We only need 0 <= 1 < len(nums) - len(pattern) because otherwise the
        # subarrays would not have enough elements to be the correct size of
        # pattern and will give index out of bounds errors.
        for i in range(len(nums) - len(pattern)):
            sub_array = nums[i : i + pat_length]
            sub_array_match = True

            for k in range(len(pattern)):
                if pattern[k] == 1:
                    if not (sub_array[k + 1] > sub_array[k]):
                        sub_array_match = False
                        break
                elif pattern[k] == 0:
                    if sub_array[k + 1] != sub_array[k]:
                        sub_array_match = False
                        break
                else:
                    if not (sub_array[k + 1] < sub_array[k]):
                        sub_array_match = False
                        break

            if sub_array_match:
                count += 1

        return count

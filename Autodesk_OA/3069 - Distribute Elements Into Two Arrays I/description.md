# 3069. Distribute Elements Into Two Arrays I

## Difficulty: Easy

## Problem Description

You are given a 1-indexed array of distinct integers `nums` of length `n`.

You need to distribute all the elements of `nums` between two arrays `arr1` and `arr2` using `n` operations:

1. In the first operation, append `nums[1]` to `arr1`
2. In the second operation, append `nums[2]` to `arr2`
3. For the `i`th operation (i > 2):
   - If the last element of `arr1` is greater than the last element of `arr2`, append `nums[i]` to `arr1`
   - Otherwise, append `nums[i]` to `arr2`

The final array `result` is formed by concatenating `arr1` and `arr2`.
For example, if `arr1 = [1,2,3]` and `arr2 = [4,5,6]`, then `result = [1,2,3,4,5,6]`.

Return the array `result`.

## Examples

### Example 1

**Input:** `nums = [2,1,3]`  
**Output:** `[2,3,1]`

**Explanation:**

1. After the first 2 operations:
   - `arr1 = [2]`
   - `arr2 = [1]`

2. In the 3rd operation:
   - Last element of `arr1 (2)` > last element of `arr2 (1)`
   - Therefore, append `nums[3]` to `arr1`

3. Final arrays:
   - `arr1 = [2,3]`
   - `arr2 = [1]`

4. Result after concatenation: `[2,3,1]`

### Example 2

**Input:** `nums = [5,4,3,8]`  
**Output:** `[5,3,4,8]`

**Explanation:**

1. After the first 2 operations:
   - `arr1 = [5]`
   - `arr2 = [4]`

2. In the 3rd operation:
   - Last element of `arr1 (5)` > last element of `arr2 (4)`
   - Therefore, append `nums[3]` to `arr1`
   - `arr1` becomes `[5,3]`

3. In the 4th operation:
   - Last element of `arr2 (4)` > last element of `arr1 (3)`
   - Therefore, append `nums[4]` to `arr2`
   - `arr2` becomes `[4,8]`

4. Final arrays:
   - `arr1 = [5,3]`
   - `arr2 = [4,8]`

5. Result after concatenation: `[5,3,4,8]`

## Constraints

- 3 ≤ n ≤ 50
- 1 ≤ nums[i] ≤ 100
- All elements in `nums` are distinct

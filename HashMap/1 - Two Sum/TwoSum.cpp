#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashSet;

        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            int numRequired = target - nums[i];

            /*
            The find() function in C++ returns an iterator pointing to the first element in
            the container that matches the specified key. If the element is not found, the
            function returns an iterator equal to the end() iterator of the container.

            For associative containers like std::unordered_map, the find() function returns
            an iterator to the element with the specified key, or end() if the element is
            not found.
            */

            if (hashSet.find(numRequired) != hashSet.end() && i != hashSet[numRequired]) {
                result = {i, hashSet[numRequired]};
                break;
            } else {
                if (hashSet.find(nums[i]) == hashSet.end()) {
                    hashSet[nums[i]] = i;
                }
            }
        }

        return result;
    }
};

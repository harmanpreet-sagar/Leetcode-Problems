#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // Alternate implementation

        // map<int, int> myMap;

        // for (int val : nums) {
        //     if (myMap.find(val) == myMap.end()) {
        //         myMap[val] = 1;
        //     }
        // }

        // int currentLength = 1;
        // int maxLength = 0;

        // for (const auto& pair : myMap) {
        //     if (myMap.find(pair.first + 1) != myMap.end()) {
        //         currentLength++;
        //     } else {
        //         currentLength = 1;
        //     }

        //     if (maxLength < currentLength) {
        //         maxLength = currentLength;
        //     }
        // }

        sort(nums.begin(), nums.end());

        int maxLength = 1;
        int currentLength = 1;

        if (nums.size() <= 1) {
            return nums.size();
        } else {
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i - 1] == (nums[i] - 1)) {
                    currentLength++;
                } else if (nums[i-1] == nums[i]) {
                    continue;
                } else {
                    currentLength = 1;
                }

                if (maxLength < currentLength) {
                    maxLength = currentLength;
                }
            }
        }

        return maxLength;
    }
};
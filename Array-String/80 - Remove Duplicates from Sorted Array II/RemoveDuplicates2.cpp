#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // nums in ascending order
        // unique element appears at most twice
        // O(1) extra memory, i.e., no hashmaps or another array


        // Since it is sorted, if a third or more element exists, it would be
        // similar to the two before it

        int k = 2;
        int length = nums.size();
        
        if (length <= 2) {
            return length;
        } 
        
        int check = nums[0];

        for (int i = 2; i < length; i++) {
            if (nums[i] != check) {
                check = nums[i - 1];
                nums[k++] = nums[i];
            } else {
                check = nums[i - 1];
            }
        }

        for (int i = 0; i < k; i ++) {
            cout << nums[i] << ", ";
        }

        cout << endl;

        return k;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 2};

    Solution soln;

    cout << soln.removeDuplicates(nums);

    return 0;
}

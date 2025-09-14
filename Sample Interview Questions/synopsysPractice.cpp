#include <vector>
#include <iostream>

using namespace std;

/*
Implement a function that given an integer array and its length, returns the
length of the longest sequence of alternating odd and even numbers. For
instance, in the array 112365546, it will return 5 (for the sequence 12365).
*/

class Solution {
public:
    int longestOddEvenSequence (vector<int> array, int length) {
        int largestLength = 1;
        int currLength = 1;

        for (int i = 1; i < length; i++) {
            if ((array[i - 1] % 2 == 0) && (array[i] % 2 == 1)) {
                currLength++;
            } else if ((array[i - 1] % 2 == 1) && (array[i] % 2 == 0)) {
                currLength++;
            } else {
                currLength = 1;
            }

            if (largestLength < currLength) {
                largestLength = currLength;
            }
        }

        return largestLength;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 1, 2, 3, 6, 5, 5, 4, 6};

    int length = nums.size();

    Solution soln;

    cout << soln.longestOddEvenSequence(nums, length) << endl;

    return 0;
}



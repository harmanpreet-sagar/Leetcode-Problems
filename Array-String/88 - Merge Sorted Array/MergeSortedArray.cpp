#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; // Final index of nums1
        int j = n - 1; // Final index of nums 2
        int k = m + n - 1; // Final index of the merged array

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // for (int i = m; i < (m + n); i++) {
        //     nums1[i] = nums2[index++];
        // }

        // Dont use sort function coz time complexity is O((m+n)*log(m*n))
        // m + n is the size of the array
        // sort(nums1.begin(), nums1.end());
    }
};

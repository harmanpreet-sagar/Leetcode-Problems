#include <vector>
#include <iostream>

using namespace std;

// The input array must be sorted previously.
int binarySearch(vector<int> arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] < target) {
            left = mid + 1;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {
            return mid;
        }
    }

    return left;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 25, 45, 54, 65, 76};
    cout << binarySearch(nums, 25);
    return 0;
}

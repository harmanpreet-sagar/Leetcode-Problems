#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int largestArea = 0;

        int start = 0;
        int end = height.size() - 1;

        while (start < end) {
            int width = end - start;
            int contHeight = min(height[start], height[end]);
            int currentArea = width * contHeight;

            largestArea = max(largestArea, currentArea);

            // We reduce the pointer based on which height is bigger is because
            // we have a greater chance of obtaining a larger area with a
            // greater height
            if (height[start] > height[end]) {
                end--;
            } else {
                start++;
            }
        }

        return largestArea;
    }
};

int main(int argc, char const *argv[])
{
    Solution soln;

    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << soln.maxArea(heights);

    return 0;
}

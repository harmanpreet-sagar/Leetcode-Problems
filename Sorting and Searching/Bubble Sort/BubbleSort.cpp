#include <vector>
#include <iostream>

using namespace std;

vector<int> bubbleSort(vector<int> inputArray) {

    vector<int> arr = inputArray;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size() - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return arr;
}

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> testCases = {
        {},                         // Empty Array
        {5},                        // Array with One Element
        {1, 2, 3, 4, 5},            // Already Sorted Array
        {5, 4, 3, 2, 1},            // Array in Descending Order
        {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5},  // Array with Duplicate Elements
        {10, -5, 8, -3, 0, 7, -1},   // Array with Negative Numbers
        {10000, 5000, 8000, 3000, 2000, 7000, 1000},  // Large Array
        {4, 2, 7, 1, 9, 5, 3, 8, 6}, // Randomized Array
        {2, 1, 3, 2, 1, 3, 2, 1, 3}  // Array with Repeated Values
    };

    for (const auto& testCase : testCases) {
        // Print test cases
        std::cout << "Original: [";
        for (size_t i = 0; i < testCase.size(); ++i) {
            std::cout << testCase[i];
            if (i < testCase.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;

        // Print sorted array
        vector<int> sortedArray = bubbleSort(testCase);
        std::cout << "Sorted: [";
        for (size_t i = 0; i < sortedArray.size(); ++i) {
            std::cout << sortedArray[i];
            if (i < sortedArray.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }

    
    return 0;
}

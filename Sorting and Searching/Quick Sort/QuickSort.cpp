#include <vector>
#include <iostream>

using namespace std;

int partition(vector<int>& a, int lowIndex, int highIndex) {
    int pivot = a[lowIndex];
    int leftWall = lowIndex;

    for (int i = lowIndex + 1; i <= highIndex; i++) {
        if (a[i] < pivot) {
            swap(a[i], a[++leftWall]);
        }
    }

    swap(a[lowIndex], a[leftWall]);

    return leftWall;
}

void qSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int pivotLocation = partition(a, low, high);
        qSort(a, low, pivotLocation - 1);
        qSort(a, pivotLocation + 1, high);
    }
}

vector<int> quickSort(vector<int> inputArray) {
    vector<int> arr = inputArray;

    int low = 0;
    int high = arr.size() - 1;

    qSort(arr, low, high);
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
        vector<int> sortedArray = quickSort(testCase);
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

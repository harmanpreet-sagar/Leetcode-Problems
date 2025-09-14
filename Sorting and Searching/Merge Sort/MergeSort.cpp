#include <vector>
#include <iostream>

using namespace std;

vector<int> merge(vector<int> a, vector<int> b) {

    vector<int> c;

    while (!a.empty() && !b.empty()) {
        if (a[0] > b[0]) {
            c.push_back(b[0]);
            b.erase(b.begin());
        } else {
            c.push_back(a[0]);
            a.erase(a.begin());
        }
    }

    while (!a.empty()) {
        c.push_back(a[0]);
        a.erase(a.begin());
    }

    while (!b.empty()) {
        c.push_back(b[0]);
        b.erase(b.begin());
    }


    return c;
}

vector<int> mergeSort(vector<int> inputArray) {

    int n = inputArray.size();

    if (n == 0 || n == 1) {
        return inputArray;
    }

    vector<int> arrayOne, arrayTwo;

    int mid = n / 2;
    int index = 0;

    // Populate the arrays
    for (int i = 0; i < n; i++)  {
        if (i < mid) {
            arrayOne.push_back(inputArray[i]);
        } else {
            arrayTwo.push_back(inputArray[i]);
        }
    }

    arrayOne = mergeSort(arrayOne);
    arrayTwo = mergeSort(arrayTwo);

    return merge(arrayOne, arrayTwo);
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
        vector<int> sortedArray = mergeSort(testCase);
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

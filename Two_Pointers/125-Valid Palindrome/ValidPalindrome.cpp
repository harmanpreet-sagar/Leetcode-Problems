#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        int start = 0;
        int end = s.size() - 1;

        while (start < end) {
            if (!isalnum(s[start])) {
                start++;
                continue;
            }

            if (!isalnum(s[end])) {
                end--;
                continue;
            }

            cout << "Current values: " << s[start] << ", " << s[end] << endl;

            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            } else {
                start++;
                end--;
            }
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution soln;
    cout << soln.isPalindrome("aa");
    return 0;
}

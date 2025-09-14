#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {

        // Create a stack to store valid directory names
        stack<string> myStack;

        // Append a '/' at the end of the path to ensure the last directory is processed
        path.push_back('/');

        // Temporary variable to store the current directory name
        string dir;

        // Iterate through each character in the path
        for (char c : path) {
            if (c == '/') {
                // If the current character is '/', check the directory name
                if (dir == "..") {
                    // If the directory name is '..', pop the top directory from the stack
                    if (!myStack.empty()) {
                        myStack.pop();
                    }
                } else if (dir != "" && dir != ".") {
                    // If the directory name is not empty or '.', push it onto the stack
                    myStack.push(dir);
                }
                // Clear the directory name for the next iteration
                dir.clear();
            } else {
                // If the current character is not '/', append it to the directory name
                dir.push_back(c);
            }
        }

        // Construct the simplified path by concatenating directories from the stack in reverse order
        string result;
        while (!myStack.empty()) {
            result = "/" + myStack.top() + result;
            myStack.pop();
        }

        // If the simplified path is empty, return '/'
        if (result.empty()) {
            return "/";
        }
        return result;
    }
};

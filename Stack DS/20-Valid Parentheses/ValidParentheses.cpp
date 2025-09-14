#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;

        int pushNumber = 0;
        int popNumber = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                parentheses.push(')');
                pushNumber++;
            } else if (s[i] == '{') {
                parentheses.push('}');
                pushNumber++;
            } else if (s[i] == '[') {
                parentheses.push(']');
                pushNumber++;
            } else {
                popNumber++;
                // Shouldn't reach this stage during the evaluation of the string
                if (parentheses.empty()) {
                    return false;
                }
                // This is the element that will be popped if pop() is used
                char poppedElement = parentheses.top(); 
                if (poppedElement != s[i]) {
                    return false;
                } else {
                    parentheses.pop();
                }
            }
        }

        if (pushNumber != popNumber) {
            return false;
        }

        return true;
    }
};
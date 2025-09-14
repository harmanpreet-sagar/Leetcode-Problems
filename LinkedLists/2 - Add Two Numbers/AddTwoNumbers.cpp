#include <cmath>
#include <string>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Have to use linked lists to carry out addition since the values are
        // out of the scope of long

        ListNode *head = new ListNode();
        ListNode *current = head;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10; // If value is 24, carry would be 2 since 24/10 = 2.4 but integer division drops the decimal
            sum %= 10; // If value is 24, sum is the current bit and 24 % 10 is 4.

            current->next = new ListNode(sum);
            current = current->next;
        }

        head = head->next;

        return head;
    }
};

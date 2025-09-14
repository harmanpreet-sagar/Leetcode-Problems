#include <cstddef>
#include <unordered_map>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {

        // O(n) Time Complexity to detect cycle

        // unordered_map<ListNode*, int> myMap;

        // if (head == NULL) {
        //     return false;
        // }

        // while (head->next != NULL) {
        //     if (myMap.find(head->next) != myMap.end()) {
        //         return true;
        //     } else {
        //         myMap[head->next] = 1;
        //         head = head->next;
        //     }
        // }

        // return false;

        // O(1) time complexity using Floyd's Tortoise and HAre algorithm to
        // detect cycles
        /*
        The way this algorithm works is that we initialize two pointers, a slow pointer
        and a fast pointer. The slow pointer moves through the linked list one node at a
        time whereas the fast pointer moves through the linked list two nodes at a time.
        If there is a cycle, the slow and the fast nodes will eventually meet. If the
        fast node reaches the end, i.e., the next pointer is a null pointer, that
        indicates that a cycle does not exist.    
        */
        if (head == nullptr || head->next == nullptr) {
            return false; // No cycle if the list has less than two nodes
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            if (slow == fast) {
                return true; // Cycle detected
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return false; // No cycle detected
    }
};

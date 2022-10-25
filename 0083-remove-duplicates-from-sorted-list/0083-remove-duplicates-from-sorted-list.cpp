/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *t1 = head;
        ListNode *temp;
        
        while (t1 -> next != NULL) {
            if (t1 -> val == t1 -> next -> val) {
                temp = t1 -> next;
                t1 -> next = t1 -> next -> next;
                delete temp;
            }
            else {
                t1 = t1 -> next;
            }
        }
        return head;
    }
};
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* cur = head;
        while (cur && cur -> val == 0) cur = cur -> next;
        head = cur;
        while (cur) {
            ListNode* tmp = cur;
            cur = cur -> next;
            while (cur && cur -> val != 0) {
                tmp -> val += cur -> val;
                cur = cur -> next;
            }
            while (cur && cur -> val == 0) cur = cur -> next;
            tmp -> next = cur;
        }
        return head;
    }
};
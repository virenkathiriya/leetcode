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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *n1 = head, *n2 = nullptr, *cur = head;
        while (--k) {
            cur = cur -> next;
        }
        n1 = cur;
        n2 = head;
        while (cur -> next) {
            cur = cur -> next;
            n2 = n2 -> next;
        }
        swap(n1 -> val, n2 -> val);
        return head;
    }
};
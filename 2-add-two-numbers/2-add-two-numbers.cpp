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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode* ans = new ListNode(0);
        ListNode* head = ans;
        while (l1 || l2) {
            int x = l1 ? l1 -> val : 0, y = l2 ? l2 -> val: 0;
            ans -> next = new ListNode((x + y + c) % 10);
            ans = ans -> next;
            c = (x + y + c) / 10;
            if (l1)
                l1 = l1 -> next;
            if (l2)
                l2 = l2 -> next;
        }
        if (c) ans -> next = new ListNode(c);
        
        return head -> next;
    }
};
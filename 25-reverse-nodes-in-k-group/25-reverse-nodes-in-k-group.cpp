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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return head;
        
        // check if there are k node left
        int kleft = k;
        ListNode* cur = head;
        while (cur && kleft) {
            cur = cur -> next;
            kleft--;
        }
        // if not, don't reverse
        if (kleft > 0) return head;
        
        ListNode *prev, *nxt;
        cur = head;
        prev = NULL;
        
        kleft = k;
        // reverse
        while (cur && kleft) {
            nxt = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = nxt;
            kleft--;
        }
        
        // if next k group possible
        if (cur != NULL) {
            head -> next = reverseKGroup(cur, k);
        }
        return prev;
    }
};
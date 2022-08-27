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
    ListNode* reverse(ListNode* head) {
        if (!head || !head -> next) return head;
        
        ListNode *rest = reverse(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        
        return rest;
    }
    
    bool isPalindrome(ListNode* head) {
        // find middle of linked list
        ListNode *s, *f;
        s = f = head;
        while (f && f -> next) {
            s = s -> next;
            f = f -> next -> next;
        }
        
        ListNode* half;
        if (f == NULL) {
            // even
            half = reverse(s);
        } else {
            // odd
            half = reverse(s -> next);
            // might remove later
        }
        
        // check 
        while (half) {
            if (half -> val == head -> val) {
                half = half -> next;
                head = head -> next;
            } else return false;
        }
        return true;
    }
};
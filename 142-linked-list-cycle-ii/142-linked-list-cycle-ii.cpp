/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *f = head, *s = head;
        if (!f || !f -> next) return NULL;
        f = f -> next -> next;
        s = s -> next;
        while (f != s && f && f -> next){
            f = f -> next -> next;
            s = s -> next;
        }
        
        if (!f || !s || !f -> next) return NULL;
        
        f = head;
        while (f != s) {
            f = f -> next;
            s = s -> next;
        }
        return f;
    }
};
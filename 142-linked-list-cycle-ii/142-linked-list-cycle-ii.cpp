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
        if (!head) return NULL;
        ListNode *f, *s;
        f = head;
        s = head;
        bool exist = false;
        while (f -> next && f -> next -> next) {
            f = f -> next -> next;
            s = s -> next;
            if (f == s) {
                exist = true;
                break;
            }
        }
        if (!exist) return NULL;
        s = head;
        while (s != f) {
            s = s -> next;
            f = f -> next;
        }
        return s;
    }
};
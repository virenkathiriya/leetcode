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
    void reorderList(ListNode* head) {
        if (!head or !head -> next) return;
        
        ListNode *s, *f;
        s = head, f = head;
        while (f -> next && f -> next -> next) {
            f = f -> next -> next;
            s = s -> next;
        }
        
        ListNode *cur = s -> next;
        s -> next = NULL;
        
        ListNode *prev = NULL;
        while (cur) {
            auto next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        
        for (auto _1 = head, _2 = prev; _1 && _2;) {
            auto next = _2 -> next;
            _2 -> next = _1 -> next;
            _1 -> next = _2;
            _2 = next;
            _1 = _1 -> next -> next;
        }
    }
};
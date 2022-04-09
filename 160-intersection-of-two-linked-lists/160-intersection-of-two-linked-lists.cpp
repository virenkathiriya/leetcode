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
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        ListNode *_1 = A;
        ListNode *_2 = B;
        while (_1 != _2) {
            _1 = _1 ? _1 -> next : B;
            _2 = _2 ? _2 -> next : A;
        }
        return _1;
    }
};
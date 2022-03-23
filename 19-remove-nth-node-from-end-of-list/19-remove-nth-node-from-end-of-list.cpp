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
    
    ListNode* removeNthFromEnd(ListNode* head, int &n) {
        ListNode *l = head, *r = head;
        while (n--) r = r -> next;
        if (!r) head = head -> next;
        else {
            while (r -> next) {
                r = r -> next;
                l = l -> next;
            }
            l -> next = l -> next -> next;
        }
        return head;
    }
}; 
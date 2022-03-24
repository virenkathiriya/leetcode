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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode();
        ListNode *p1 = list1, *p2 = list2, *cur = head;
        while (p1 && p2) {
            if (p1 -> val > p2 -> val) {
                cur -> next = new ListNode(p2 -> val);
                p2 = p2 -> next;
            } else {
                cur -> next = new ListNode(p1 -> val);
                p1 = p1 -> next;
            }
            cur = cur -> next;
        }
        
        while (p1) {
            cur -> next = new ListNode(p1 -> val);
            p1 = p1 -> next;
            cur = cur -> next;
        }
        
        while (p2) {
            cur -> next = new ListNode(p2 -> val);
            p2 = p2 -> next;
            cur = cur -> next;
        }
        
        return head -> next;
    }
};
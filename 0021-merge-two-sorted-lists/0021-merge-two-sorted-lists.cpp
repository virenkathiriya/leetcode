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
        
        ListNode *t1 = list1, *t2 = list2;
        
        ListNode *sortedList = new ListNode(-1);
        ListNode *cur = sortedList;
        while (t1 != NULL && t2 != NULL) {
            if (t1 -> val < t2 -> val) {
                cur -> next = new ListNode(t1 -> val);
                t1 = t1 -> next;
            } else {
                cur -> next = new ListNode(t2 -> val);
                t2 = t2 -> next;
            }
            cur = cur -> next;
        }
        
        while (t1 != NULL) {
            cur -> next = new ListNode(t1 -> val);
            t1 = t1 -> next;
            cur = cur -> next;
        }
        
        
        while (t2 != NULL) {
            cur -> next = new ListNode(t2 -> val);
            t2 = t2 -> next;
            cur = cur -> next;
        }
        
        return sortedList -> next;
    }
};
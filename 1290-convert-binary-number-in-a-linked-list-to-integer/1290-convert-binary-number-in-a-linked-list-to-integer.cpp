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
    int getDecimalValue(ListNode* h) {
        int ans = 0;
        while (h) {
            ans <<= 1;
            if (h -> val) ans |= 1;
            h = h -> next;
        }
        return ans;
    }
};
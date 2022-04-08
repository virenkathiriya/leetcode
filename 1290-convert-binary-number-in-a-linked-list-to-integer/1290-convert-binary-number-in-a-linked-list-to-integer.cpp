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
        string s;
        while (h) {
            s += ((h -> val) + '0');
            h = h -> next;
        }
        int ans = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
            ans += (1 << (n - 1 - i));
        }
        return ans;
    }
};
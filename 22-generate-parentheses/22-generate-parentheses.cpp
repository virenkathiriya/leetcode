class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        n *= 2;
        rec(ans, "", n, 0, 0, 0);
        return ans;
    }
    
    void rec(vector<string> &ans, string cur, int &n, int ptr, int o, int c) {
        if (ptr == n) {
            ans.push_back(cur);
            return;
        }
        if (o < n / 2) {
            cur += "(";
            rec(ans, cur, n, ptr + 1, o + 1, c);
            cur.pop_back();
        }
        
        if (o > c) {
            cur += ")";
            rec(ans, cur, n, ptr + 1, o, c + 1);
            cur.pop_back();
        }
    }
};
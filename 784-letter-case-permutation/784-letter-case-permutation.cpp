class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        int n = s.size();
        f(n, s, 0, ans);
        return ans;
    }
    
    void f(int &n, string cur, int ind, vector<string> &ans) {
        if (ind >= n) {
            ans.push_back(cur);
            return;
        }
        if (!isalpha(cur[ind])) {
            f(n, cur, ind + 1, ans);
            return;
        }
        f(n, cur, ind + 1, ans);
        cur[ind] = (isupper(cur[ind])) ? tolower(cur[ind]) : toupper(cur[ind]);
        f(n, cur, ind + 1, ans);
    }
};
class Solution {
public:
    bool ifP(string& s, int i, int j) {
        while (i < j) if (s[i++] != s[j--]) return false; return true; 
    }
    void f(vector<vector<string>>& ans, vector<string>& cur, string& s, int i, int n) {
        if (i == n) {ans.push_back(cur); return;}
        for (int j = i; j < n; j++) {
            if (ifP(s, i, j)) {
                cur.push_back(s.substr(i, j - i + 1));
                f(ans, cur, s, j + 1, n);
                cur.pop_back();
            }
        }
    } 
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> tmp;
        f(ans, tmp, s, 0, s.size());
        return ans;
    }
};
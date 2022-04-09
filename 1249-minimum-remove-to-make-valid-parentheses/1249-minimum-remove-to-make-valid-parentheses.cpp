class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        int nO = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                nO++;
            } else if (s[i] == ')') {
                if (nO > 0) nO--;
                else continue;
            }
            ans += s[i];
        }
        if (nO > 0) {
            int i = ans.size() - 1;
            while (i >= 0 && nO > 0) {
                if (ans[i] == '(') {
                    ans[i] = 'R';
                    nO--;
                }
                i--;
            }
            ans.erase(remove(ans.begin(), ans.end(), 'R'), ans.end());
        }
        return ans;
    }
};
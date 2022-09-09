class Solution {
public:
    vector<int> movesToStamp(string s, string t) {
        vector<int> ans;
        int n = t.size(), m = s.size();
        while (true) {
            int cnt = 0;
            for (int i = 0; i <= n - m; i++) {
                bool ifStampReversible = false;
                for (int j = 0; j < m; j++) {
                    if (t[j + i] != '.' && (t[j + i] != s[j])) {
                        ifStampReversible = false; 
                        break;
                    } else if (t[j + i] != '.') {
                        ifStampReversible = true;
                    }
                }
                if (ifStampReversible) {
                    for (int j = 0; j < m; j++) t[i + j] = '.';
                    ans.push_back(i);
                    cnt++;
                }
            }
            if (cnt == 0) return {};
            if (count(t.begin(), t.end(), '.') == n) break;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
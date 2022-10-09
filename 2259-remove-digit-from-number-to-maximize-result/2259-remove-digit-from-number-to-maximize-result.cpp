class Solution {
public:
    string removeDigit(string s, char digit) {
        int N = s.size();
        string ans;
        for (int i = N - 1; i >= 0; i--) {
            if (s[i] == digit) {
                string c = s.substr(0, i) + (i == N - 1 ? "" : s.substr(i + 1));
                if (c > ans) {
                    ans = c;
                }
            }
        }
        return ans;
    }
};
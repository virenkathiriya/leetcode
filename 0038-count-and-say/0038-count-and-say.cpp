class Solution {
public:
    string countAndSay(int n) {
        string ans;
        if (n == 1) ans = "1";
        else {
            string s = countAndSay(n - 1);
            int cnt = 1, N = s.size();
            for (int i = 1; i < N; ++i) {
                if (s[i] == s[i - 1]) {
                    cnt++;
                } else {
                    ans += to_string(cnt) + string(1, s[i  - 1]);
                    cnt = 1;
                }
            }
            if (cnt > 0) ans += to_string(cnt) + string(1, s[N - 1]);
        }
        return ans;
    }
};
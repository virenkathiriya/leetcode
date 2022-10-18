unordered_map<int, string> cache;
class Solution {
public:
    string countAndSay(int n) {
        if (!cache[n].empty()) return cache[n];
        if (n == 1) return cache[n] = "1";
        
        string s = countAndSay(n - 1);
        string ans = "";
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
        return cache[n] = ans;
    }
};
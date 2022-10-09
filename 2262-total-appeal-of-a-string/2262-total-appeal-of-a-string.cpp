#define ll long long
class Solution {
public:
    long long appealSum(string s) {
        vector<int> p(26, 0);
        ll N = s.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            int x = s[i] - 'a';
            ans += (i + 1 - p[x]) * (N - i);
            p[x] = i + 1; 
        }
        return ans;
    }
};
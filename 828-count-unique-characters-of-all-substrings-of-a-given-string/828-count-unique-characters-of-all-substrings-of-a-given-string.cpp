class Solution {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>> p(26, vector<int> (2, -1));
        int N = s.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            int x = s[i] - 'A';
            ans += (p[x][0] - p[x][1]) * (i - p[x][0]);
            p[x][1] = p[x][0];
            p[x][0] = i;
        }
        for (int x = 0; x < 26; x++) ans += (p[x][0] - p[x][1]) * (N - p[x][0]);
        return ans;
    }
};
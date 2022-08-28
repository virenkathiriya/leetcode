class Solution {
public:
    int garbageCollection(vector<string>& g, vector<int>& t) {
        int ans = 0;
        string s = "MPG";
        int N = g.size();
        for (int i = 1; i < t.size(); i++) t[i] += t[i - 1];
        for (char &c: s) {
            int end = 0, cnt = 0;
            for (int i = N - 1; i >= 0; i--) {
                for (char &ch: g[i]) cnt += c == ch;
                if (end == 0 && cnt > 0) {
                    end = i;
                }
            }
            ans += cnt;
            if (end != 0)
            ans += t[end - 1];
        }
        return ans;
    }
};
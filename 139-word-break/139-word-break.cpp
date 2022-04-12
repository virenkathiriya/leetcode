class Solution {
public:
    bool wordBreak(string s, vector<string>& wd) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        priority_queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int ind = q.top();
            if (ind == n) return true;
            q.pop();
            for (string &w: wd) {
                int m = w.length();
                if (m + ind <= n && s.substr(ind, m) == w){ 
                    if (!dp[ind + m]) {
                        dp[ind + m] = true;
                        q.push(ind + m);
                    }
                }
            }
        }
        return false;
    }
};
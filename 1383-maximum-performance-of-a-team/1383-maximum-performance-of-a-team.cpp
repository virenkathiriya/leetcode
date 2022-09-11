class Solution {
public:
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        vector<pair<int, int>> vp;
        const int MOD = 1000000007;
        for (int i = 0; i < s.size(); i++) vp.emplace_back(e[i], s[i]);
        sort(vp.rbegin(), vp.rend());
        
        // for min efficiency
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int64_t rsum = 0;
        int64_t ans = 0;
        for (auto [e, s]: vp) {
            pq.push(s);
            rsum += s;
            if (pq.size() > k) {
                rsum -= pq.top();
                pq.pop();
            }
            ans = max(rsum * e, ans);
        }
        return ans % MOD;
    }
};
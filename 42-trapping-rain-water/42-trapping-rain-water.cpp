class Solution {
public:
    int trap(vector<int>& v) {
        int N = v.size();
        int ans = 0;
        
        vector<int> l(N, 0), r(N, 0);
        l[0] = v[0];
        for (int i = 1; i < N; i++) l[i] = max(l[i - 1], v[i]);
        r[N - 1] = v[N - 1];
        for (int i = N - 2; i >= 0; i--) r[i] = max(r[i + 1], v[i]);
        
        for (int i = 0; i < N; i++) ans += min(l[i], r[i]) - v[i];
        return ans;
    }
};
class Solution {
public:
    int countSubarrays(vector<int>& v, int k) {
        int N = v.size(), ans = 0;
        auto it = find(v.begin(), v.end(), k);
        int p = it - v.begin();
        
        vector<int> f(2 * N + 1, 0);
        
        int b = 0;
        for (int i = p; i < N; ++i) {
            b += (v[i] == k) ? 0: ((v[i] > k) ? 1: -1);
            f[b + N]++;
        }
        
        b = 0;
        for (int i = p; i >= 0; --i) {
            b += (v[i] == k) ? 0: ((v[i] > k) ? 1: -1);
            ans += f[N - b] + f[N + 1 - b];
        }
        
        return ans;
    }
};
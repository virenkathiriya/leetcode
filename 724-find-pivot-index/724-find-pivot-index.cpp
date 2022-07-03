class Solution {
public:
    int pivotIndex(vector<int>& v) {
        int N = v.size();
        for (int i = 1; i < N; i++) v[i] += v[i - 1];
        int ans = -1;
        for (int i = N - 1; i >= 0; --i) {
            int l = i > 0 ? v[i - 1] : 0;
            int r = v[N - 1] - v[i];
            if (l == r) ans = i;
        }
        return ans;
    }
};
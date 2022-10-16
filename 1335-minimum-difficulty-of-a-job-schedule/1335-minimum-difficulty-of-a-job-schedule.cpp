class Solution {
public:
    vector<int> seg;
    
    void b(int i, vector<int> &v, int l, int r) {
        if (l == r) { seg[i] = v[l]; return; }
        int m = l + (r - l) / 2;
        b(2 * i + 1, v, l, m), b(2 * i + 2, v, m + 1, r);
        seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]);
    }
    
    int q(int ind, int i, int j, int l, int r) {
        if (l <= i and r >= j) return seg[ind];
        if (l > j or r < i) return INT_MIN;
        int m = i + (j - i) / 2;
        return max(q(2 * ind + 1, i, m, l, r), q(2 * ind + 2, m + 1, j, l, r));
    }
    
    int f(int i, int d, int N, vector<int>&v, vector<vector<int>> &dp) {
        if (dp[i][d] != INT_MAX) return dp[i][d];
        
        if (d == 0) return dp[i][d] = q(0, 0, N - 1, i, N - 1);
        
        int res = INT_MAX;
        for (int j = i + 1; j < N; j++) {
            int rem = f(j, d - 1, N, v, dp);
            if (rem == INT_MAX) continue;
            res = min(res, q(0, 0, N - 1, i, j - 1) + rem);
        }
        
        return dp[i][d] = res;
    }
    
    int minDifficulty(vector<int>& v, int d) {
        int N = v.size();
        if (N < d) return -1;
        
        seg.resize(N * 4 + 1);
        b(0, v, 0, N - 1);
        vector<vector<int>> dp(N + 1, vector<int> (d + 1, INT_MAX));
        
        return f(0, d - 1, N, v, dp);
    }
};
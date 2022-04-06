class Solution {
public:
    int threeSumMulti(vector<int>& v, int t) {
        int ans = 0, MOD = 1000000007;
        int n = v.size();
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            int a = v[i];
            if (a > t) continue;
            int l = i + 1, r = n - 1;
            int T = t - a;
            while (l < r) {
                int b = v[l];
                int c = v[r];
                
                if (b + c == T) {
                    if (b == c) {
                        int m = r - l + 1;
                        m = (m * (m - 1)) / 2;
                        ans = (ans + m) % MOD;
                        break;
                    } else {
                        int cntb = 0;
                        int cntc = 0;
                        while (l < r && v[l] == b) {l++, cntb++;}
                        while (l <= r && v[r] == c) {r--, cntc++;}
                        
                        ans = (ans + (cntb * cntc)) % MOD;
                    }
                } else if (b + c < T) l++;
                else r--;
            }
        }
        return ans;
    }
};
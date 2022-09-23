class Solution {
public:
    int concatenatedBinary(int n) {
        long ans = 0;
        int mod = 1e9 + 7;
        int bl = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i & (i - 1)) == 0) bl++;
            ans = ((ans << bl) | i) % mod;
        }
        return ans;
    }
};
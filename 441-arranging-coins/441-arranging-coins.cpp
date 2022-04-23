class Solution {
public:
    int arrangeCoins(int n) {
        int l = 1, r = n;
        if (n == 1) return 1;
        while (l <= r) {
            long long m = l + (r - l) / 2;
            long long m2 = (m * (m + 1)) / 2;
            
            if (m2 == n) return m;
            (m2 < n) ? l = m + 1 : r = m - 1;
        }
        return r;
    }
};
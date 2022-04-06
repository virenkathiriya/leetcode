class Solution {
public:
    int uniquePaths(int m, int n) {
        int x = m + n - 2;
        int mn = max(m - 1, n - 1);
        long long ans = 1;
        long long i = x - mn + 1, j = 2;
        while (i <= x || j <= mn) {
            while (j <= mn && ans % j == 0) {
                ans /= j;
                j++;
            }
            if (i > x) continue;
            ans *= i;
            i++;
        }
        return ans;
    }
};
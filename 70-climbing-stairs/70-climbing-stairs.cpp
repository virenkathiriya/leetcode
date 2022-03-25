class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int m = 2, a = 1, b = 2;
        while (m < n) {
            swap(a, b);
            b += a;
            m++;
        }
        return b;
    }
};
class Solution {
public:
    int integerBreak(int n) {
        if (n < 4) return n - 1;
        if (n % 3 == 0) {
            return powl(3, n / 3);
        } else if (n % 3 == 1) {
            return powl(3, n / 3 - 1) * 4;
        } else {
            return powl(3, n / 3) * 2;
        }
    }
};
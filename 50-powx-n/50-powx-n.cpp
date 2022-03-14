class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        bool x_n = x < 0, n_n = n < 0, n_o = n % 2;
        x = abs(x); n = abs(n);
        while (n > 0) {
            if (n % 2 == 1) ans *= x;
            x *= x;
            n /= 2;
        }
        if (x_n && n_o) ans *= -1;
        if (n_n) ans = 1.0 / ans;
        return ans;
    }
};
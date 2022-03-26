class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 2 || n == 1) return 1;
        int a = 1, b = 1;
        n -= 2;
        while (n--) {
            swap(a, b);
            b += a;
        }
        return b;
    }
};
class Solution {
public:
    int rev(int x) {
        int n = 0;
        while (x > 0) {
            int d = x % 10;
            n = n * 10 + d;
            x /= 10;
        }
        return n;
    }
    
    bool sumOfNumberAndReverse(int num) {
        for (int i = 0; i <= num; i++) if (i + rev(i) == num) return true;
        return false;
    }
};
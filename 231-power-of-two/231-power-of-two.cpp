class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt = 0;
        while (n > 0) {
            if (n % 2 == 1) cnt++;
            n >>= 1;
        }
        return cnt == 1;
    }
};
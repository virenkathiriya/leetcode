class Solution {
public:
    int reverse(int x) {
        bool is_n = x < 0;
        int res = 0;
        while(x) {
            if(INT_MAX / 10 < res || (INT_MIN / 10 > res && is_n)) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        if((is_n && res > 0) || (!is_n && res < 0)) return 0;
        return res;
    }
};
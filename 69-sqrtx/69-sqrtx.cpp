class Solution {
public:
    int mySqrt(int x) {
        if(!x) return x;
        if(x == 1) return 1;
        int l = 1, r = x;
        while(l <= r) {
            long long m = l + (r - l) / 2;
            long long m2 = m * m;
            if(m2 == x) return m;
            if (m2 > x) {
                r = m - 1;
            } else {
                l = m + 1;
            }    
        }
        
        return l - 1;
    }
};
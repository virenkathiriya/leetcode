class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = 46340;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int sq = m * m;
            if (sq == num) return true;
            (sq < num) ? l = m + 1: r = m - 1; 
        }
        return false;
    }
};
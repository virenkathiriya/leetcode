class Solution {
public:
    bool increasingTriplet(vector<int>& v) {
        int f = INT_MAX, s = INT_MAX;
        for (int &x: v) {
            if (x <= f) {
                f = x;
            } else if (x <= s) {
                s = x;
            } else {
                return true;
            }
        }
        return false;
    }
};
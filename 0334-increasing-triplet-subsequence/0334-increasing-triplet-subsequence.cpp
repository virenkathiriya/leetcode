class Solution {
public:
    bool increasingTriplet(vector<int>& v) {
        int a, b;
        a = b = INT_MAX;
        for (int &x: v) if (x <= a) a = x; else if (x <= b) b = x; else return true;
        return false;
    }
};
class Solution {
public:
    vector<int> sortByBits(vector<int>& v) {
        sort(v.begin(), v.end(), [&](const int &a, const int &b) {
            int x = __builtin_popcount(a);
            int y = __builtin_popcount(b);
            if (x == y) return a < b;
            return x < y;
        });
        return v;
    }
};
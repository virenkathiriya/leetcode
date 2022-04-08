class Solution {
public:
    vector<int> getStrongest(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        int m = v[(v.size() - 1) / 2];
        sort(v.begin(), v.end(), [&](const int &a, const int &b) {
            if (abs(a - m) == abs(b - m)) return a > b;
            return abs(a - m) > abs(b - m);
        });
        v.resize(k);
        return v;
    }
};
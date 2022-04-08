class Solution {
public:
    vector<int> getStrongest(vector<int>& v, int k) {
        int n = v.size();
        nth_element(v.begin(), v.begin() + (n - 1) / 2, v.end());
        int m = v[(n - 1) / 2];
        nth_element(v.begin(), v.begin() + k, v.end(), [&](const int &a, const int &b) {
            if (abs(a - m) == abs(b - m)) return a > b;
            return abs(a - m) > abs(b - m);
        });
        v.resize(k);
        return v;
    }
};
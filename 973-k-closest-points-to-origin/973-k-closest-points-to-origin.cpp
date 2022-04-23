class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        nth_element(begin(p), begin(p) + k, end(p), [&](const vector<int> &a, const vector<int> &b) {
            return abs(a[0] * a[0] + a[1] * a[1]) < abs(b[0] * b[0] + b[1] * b[1]);
        });
        p.resize(k);
        return p;
    }
};
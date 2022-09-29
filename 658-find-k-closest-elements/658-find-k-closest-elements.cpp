class Solution {
public:
    vector<int> findClosestElements(vector<int>& v, int k, int x) {
        sort(v.begin(), v.end(), [&](const int &a, const int &b) {
            return (abs(a - x) == abs(b - x)) ? a < b : abs(a - x) < abs(b - x);
        });
        v.resize(k);
        sort(v.begin(), v.end());
        return v;
    }
};
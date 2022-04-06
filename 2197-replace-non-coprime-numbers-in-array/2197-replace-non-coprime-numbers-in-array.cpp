class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& v) {
        int r = 0;
        for (int &x: v) {
            v[r++] = x;
            while (r > 1 && __gcd(v[r - 1], v[r - 2]) != 1) {
                v[r - 2] = ((v[r - 1] * 1LL * v[r - 2]) / (__gcd(v[r - 1], v[r - 2])));
                r--;
            }
        }
        v.resize(r);
        return v;
    }
};
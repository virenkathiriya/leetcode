class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& v) {
        sort(v.begin(), v.end());
        int d = v[1] - v[0];
        bool ok = true;
        for (int i = 2; i < v.size(); i++) ok &= v[i] - v[i - 1] == d;
        return ok;
    }
};
class Solution {
public:
    vector<int> buildArray(vector<int>& v) {
        int N = v.size();
        for (int i = 0; i < N; i++) {
            v[i] += (v[v[i] % 10000] % 10000) * 10000;
        }
        for (int &x: v) x /= 10000;
        return v;
    }
};
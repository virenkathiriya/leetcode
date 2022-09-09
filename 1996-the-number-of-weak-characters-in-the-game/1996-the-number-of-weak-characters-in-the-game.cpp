class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), [&](const vector<int> &a, const vector<int> &b) { return (a[0] == b[0]) ? a[1] > b[1]: a[0] < b[0]; });
        int mxTillI = 0, ans = 0;
        for (int i = v.size() - 1; i >= 0; --i) ans += mxTillI > v[i][1], mxTillI = max(mxTillI, v[i][1]);
        return ans;
    }
};
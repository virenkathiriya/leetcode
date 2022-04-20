class Solution {
public:
    int findTheDistanceValue(vector<int>& a, vector<int>& b, int d) {
        sort(begin(b), end(b));
        int ans = 0;
        for (int &x: a)  if (upper_bound(begin(b), end(b), x + d) == lower_bound(begin(b), end(b), x - d)) ++ans;
        return ans;
    }
};
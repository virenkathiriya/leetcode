class Solution {
public:
    double average(vector<int>& salary) {
        int mn = INT_MAX; int mx = INT_MIN;
        double sum = 0;
        for (int &x: salary) {
            mn = min(mn, x);
            mx = max(mx, x);
            sum += x;
        }
        return (sum - mn - mx) /(1.0 * (salary.size() - 2));
    }
};
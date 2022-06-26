class Solution {
public:
    int solve(vector<int>& a, vector<int>& b) {
        int mx = INT_MIN, maxe = 0;
        for (int i = 0; i < a.size(); i++) {
            maxe = maxe + b[i] - a[i];
            mx = max(mx, maxe);
            maxe = max(maxe, 0);
        }
        return (mx < 0 ? 0 : mx) + accumulate(a.begin(), a.end(), 0);
    }
    
    int maximumsSplicedArray(vector<int>& a, vector<int>& b) {
        return max(solve(a, b), solve(b, a));
    }
};
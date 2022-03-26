class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {
        // int up = upper_bound(a.begin(), a.end(), target) - a.begin();
        int n = a.size();
        if (n == 0) return {-1, -1};
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (a[m] > target) r = m - 1;
            else l = m + 1;
        }
        int up = (r >= 0 && a[r] == target) ? r : -1;
        int low = lower_bound(a.begin(), a.end(), target) - a.begin();
        if(low >= 0 && low < a.size()) {
            if(a[low] != target) low = -1;
        } else {
            low = -1;
        }
        return {low, up};
    }
};
class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {
        int up = upper_bound(a.begin(), a.end(), target) - a.begin();
        if(up > 0) {
            if(a[up - 1] != target) up = -1;
            else up--;
        } else {
            up = -1;
        }
        int low = lower_bound(a.begin(), a.end(), target) - a.begin();
        if(low >= 0 && low < a.size()) {
            if(a[low] != target) low = -1;
        } else {
            low = -1;
        }
        return {low, up};
    }
};
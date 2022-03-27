class Solution {
public:
    void sortColors(vector<int>& v) {
        int n = v.size();
        int l = 0, r = n - 1;
        for (int i = l; i <= r && i < n;) {
            if (v[i] == 0) {
                swap (v[l], v[i]);
                l++;
            } else if (v[i] == 2) {
                swap (v[r], v[i]);
                r--;
            } else {
                i++;
            }
            
            if (i < l) i = l;
        }
    }
};
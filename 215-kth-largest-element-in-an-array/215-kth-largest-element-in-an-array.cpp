class Solution {
public:
    int findKthLargest(vector<int>& v, int k) {
        int n = v.size();
        nth_element(v.begin(), v.begin() + n - k, v.end());
        return v[n - k];
    }
};
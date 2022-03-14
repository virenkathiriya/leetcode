class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
        int N = v.size();
        int l = 0, r = N - 1;
        while (l < r) {
            if (v[l] + v[r] == t) {
                return {l + 1, r + 1};
            }
            if (v[l] + v[r] > t) {
                r--;
            } else {
                l++;
            }
        }
        return {-1, -1};
    }
};
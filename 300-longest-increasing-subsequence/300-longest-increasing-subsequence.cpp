class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<int> seq(1, v[0]);
        for (int i = 1; i < n; i++) {
            if (seq.back() < v[i]) seq.push_back(v[i]);
            else {
                *lower_bound(seq.begin(), seq.end(), v[i]) = v[i];
            }
        }
        return seq.size();
    }
};
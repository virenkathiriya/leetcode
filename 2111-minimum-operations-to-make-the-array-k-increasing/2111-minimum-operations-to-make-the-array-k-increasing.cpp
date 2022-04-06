class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<int> seq(1, v[0]);
        for (int i = 1; i < n; i++) {
            if (seq.back() <= v[i]) seq.push_back(v[i]);
            else {
                auto up = upper_bound(seq.begin(), seq.end(), v[i]);
                if (up == seq.end()) {
                    seq.push_back(v[i]);
                } else {
                    *up = v[i];
                }
            }
        }
        return seq.size();
    }
    
    int kIncreasing(vector<int>& v, int k) {
        int n = v.size();
        int ans = 0;
        for (int i = 0; i < k; i++) {
            vector<int> a;
            for (int j = i; j < n; j += k) a.push_back(v[j]);
            ans += (a.size() - lengthOfLIS(a));
        }
        return ans;
    }
};
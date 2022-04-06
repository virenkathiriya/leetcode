class Solution {
public:
    int kIncreasing(vector<int>& v, int k) {
        int n = v.size();
        int ans = 0;
        for (int i = 0; i < k; i++) {
            vector<int> seq(1, v[i]);
            for (int j = i + k; j < n; j += k) 
                if (seq.back() <= v[j]) seq.push_back(v[j]);
                else *upper_bound(seq.begin(), seq.end(), v[j]) = v[j];
            ans += seq.size();
        }
        return n - ans;
    }
};
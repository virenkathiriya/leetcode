class Solution {
public:
    bool carPooling(vector<vector<int>>& vp, int capacity) {
        vector<int> x(1001, 0);
        for (vector<int> &v: vp) {
            x[v[1]] += v[0];
            x[v[2]] -= v[0];
        }
        
        for (int i = 1; i < 1001; i++) x[i] += x[i - 1];
        return (*max_element(x.begin(), x.end()) <= capacity);
    }
};
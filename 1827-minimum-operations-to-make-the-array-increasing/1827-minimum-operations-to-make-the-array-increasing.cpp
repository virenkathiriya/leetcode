class Solution {
public:
    int minOperations(vector<int>& v) {
        int ans = 0;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] > v[i - 1]) continue;
            ans += v[i - 1] + 1 - v[i]; 
            v[i] = v[i - 1] + 1;
        }
        return ans;
    }
};
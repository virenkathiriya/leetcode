class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& v, vector<vector<int>>& q) {
        int sum = 0;
        for (int &x: v) sum += (x % 2 == 0) ? x : 0;
        vector<int> ans;
        for (vector<int> &Q: q) {
            int index = Q[1];
            int val = Q[0] + v[index];
            if (v[index] % 2 == 0) {
                if (val % 2 == 0) {
                    sum += val - v[index];
                } else {
                    sum -= v[index];
                }
            } else {
                if (val % 2 == 0) {
                    sum += val;
                }
            }
            v[index] = val;
            ans.push_back(sum);
        }
        return ans;
    }
};
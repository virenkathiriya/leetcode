class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& v, vector<vector<int>>& qu) {
        vector<int> ans;
        int sum = 0;
        for (int &x: v) {
            if (x % 2 == 0) sum += x;
        }
        
        for (auto &q: qu) {
            int val = q[0];
            int ind = q[1];
            
            if (v[ind] % 2) {
                v[ind] += val;
                if (val % 2)
                    sum += v[ind];
            } else {
                if (val % 2) {
                    sum -= v[ind];
                    v[ind] += val;
                } else {
                    sum += val;
                    v[ind] += val;
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
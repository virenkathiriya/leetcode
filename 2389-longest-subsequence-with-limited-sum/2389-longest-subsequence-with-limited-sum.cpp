class Solution {
public:
    vector<int> answerQueries(vector<int>& v, vector<int>& q) {
        sort(v.begin(), v.end());
        for (int i = 1; i < v.size(); i++) v[i] += v[i - 1];
        for (int &x: q) {
            auto it = upper_bound(v.begin(), v.end(), x);
            if (it == v.end()) {
                if (x < v[0]) {
                    x = 0;
                } else {
                    x = v.size(); 
                }
            } else {
                it--;
                x = it - v.begin() + 1;
            }
        }
        return q;
    }
};
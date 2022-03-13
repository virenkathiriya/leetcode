class Solution {
public:
    vector<int> sortedSquares(vector<int>& v) {
        int N = v.size();
        vector<int> res(N);
        int l = 0, r = N - 1;
        for(int i = N - 1; i >= 0; i--) {
            if(abs(v[l]) > abs(v[r])) {
                res[i] = v[l] * v[l];
                l++;
            } else {
                res[i] = v[r] * v[r];
                r--;
            }
        }  
        return res;
    }
};
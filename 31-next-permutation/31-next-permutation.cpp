class Solution {
public:
    void nextPermutation(vector<int>& v) {
        if(v.size() == 1) return;
        int N = v.size();
        int i = N - 2, j = N - 1;
        while(i >= 0 && v[i] >= v[i + 1]) i--;
        if(i >= 0) {
            while(j >= i && v[i] >= v[j]) j--;
            swap(v[i], v[j]);
        } else {
            reverse(v.begin(), v.end());
            return;
        }
        if (i + 1 < N)
            reverse(v.begin() + i + 1, v.end());
    }
};
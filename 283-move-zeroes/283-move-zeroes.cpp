class Solution {
public:
    void moveZeroes(vector<int>& v) {
        int N = v.size();
        for (int r = 0, w = 0; r < N; r++) {
            if (v[r]) {
                swap(v[w], v[r]);
                w++;
            }
        }
    }
};
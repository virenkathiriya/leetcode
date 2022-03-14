class Solution {
public:
    void moveZeroes(vector<int>& v) {
        int N = v.size();
        int w = -1;
        for (int i = 0; i < N; i++) {
            if (v[i]) {
                w++;
                v[w] = v[i];
                if (i != w)
                    v[i] = 0;
            }
        }
        w++;
        while (w < N) v[w++] = 0;
    }
};
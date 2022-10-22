class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int r = 1, w = 1;
        int N = v.size();
        int cnt = 1;
        
        while (r < N) {
            if (v[r] == v[r - 1]) {
                if (cnt < 2) { v[w] = v[r], w++, cnt++;}
                r++;
            } else {
                v[w] = v[r];
                cnt = 1;
                r++, w++;
            }
        }
        
        return w;
    }
};
class Solution {
public:
    int arraySign(vector<int>& v) {
        int cntN = 0;
        bool ze = false;
        for (int &x: v) {
            cntN += (x  < 0);
            ze |= !x;
        }
        if (ze) return 0;
        if (cntN % 2) return -1;
        return 1;
    }
};
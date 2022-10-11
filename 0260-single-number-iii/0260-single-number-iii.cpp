class Solution {
public:
    vector<int> singleNumber(vector<int>& v) {
        int x = 0, a = 0;
        for (int &i: v) 
            x ^= i;
        int bit = 31 - __builtin_clz(x);
        for (int &i: v) 
            if (i & (1 << bit)) 
                a ^= i;
        return {a, a ^ x};
    }
};
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& v, int k) {
        reverse(v.begin(), v.end());
        int i = 0;
        int n = v.size();
        bool c = false;
        while (k || i < n) {
            int d = k % 10;
            int dN = i < n ? v[i]: 0;
            int aD = (d + dN + c);
            if (i < n) {
                v[i] = aD % 10;
            } else {
                v.push_back(aD % 10);
            }
            c = aD / 10;
            k /= 10;
            i++;
        }
        if (c) {
            v.push_back(1);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};
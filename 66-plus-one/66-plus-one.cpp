class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        int c = 1;
        for(int i = v.size() - 1; i >= 0; i--) {
            int sum = v[i] + c;
            v[i] = sum % 10;
            c = sum / 10;
        }
        if(c > 0) v.insert(v.begin(), c);
        return v;
    }
};
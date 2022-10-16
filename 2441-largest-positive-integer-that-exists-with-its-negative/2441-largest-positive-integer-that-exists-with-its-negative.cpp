class Solution {
public:
    int findMaxK(vector<int>& v) {
        sort(v.begin(), v.end());
        int N = v.size();
        int i = 0, j = N - 1;
        while (i < j) {
            if (v[i] * -1 == v[j]) return v[j];
            (abs(v[i]) > abs(v[j])) ? i++ : j--;
        }
        return -1;
    }
};
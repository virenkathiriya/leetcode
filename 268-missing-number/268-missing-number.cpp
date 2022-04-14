class Solution {
public:
    int missingNumber(vector<int>& v) {
        int n = v.size();
        return (n * (n + 1)) / 2 - accumulate(v.begin(), v.end(), 0);
    }
};
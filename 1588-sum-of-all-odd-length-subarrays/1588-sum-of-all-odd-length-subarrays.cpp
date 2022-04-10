class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& v) {
        int n = v.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ((n - i) * (i + 1) + 1) / 2 * v[i];
        }
        return sum;
    }
};
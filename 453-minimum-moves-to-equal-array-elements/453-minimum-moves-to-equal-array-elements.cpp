class Solution {
public:
    int minMoves(vector<int>& v) {
        long long N = v.size();
        long long sum = accumulate(v.begin(), v.end(), 0);
        long long mn = *min_element(v.begin(), v.end());
        return sum - mn * N;
    }
};
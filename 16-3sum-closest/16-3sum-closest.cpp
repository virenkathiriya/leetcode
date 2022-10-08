class Solution {
public:
    int threeSumClosest(vector<int>& v, int t) {
        sort(v.begin(), v.end());
        int N = v.size();
        int ans = v[0] + v[1] + v[2];
        for (int i = 0; i < N - 2; i++) {
            int sum = v[i] + twoSumClosest(v, t - v[i], i + 1, N - 1);
            if (abs(t - sum) < abs(t - ans)) ans = sum;
        }
        return ans;
    }
    
    int twoSumClosest(vector<int> &v, int t, int i, int j) {
        int ans = v[i] + v[j];
        while (i < j) {
            int sum = v[i] + v[j];
            if (abs(t - sum) < abs(t - ans)) ans = sum;
            (sum > t) ? j--: i++;
        }
        return ans;
    }
};
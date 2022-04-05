class Solution {
public:
    int largestPerimeter(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size();
        for (int i = n - 3; i >= 0; i--) {
            if (v[i + 1] + v[i] > v[i + 2]) {
                return v[i + 1] + v[i] + v[i + 2];
            }
        }
        return 0;
    }
};
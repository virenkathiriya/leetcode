class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        vector<vector<int>> ans;
        int n = v.size();
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            if (v[i] > 0) continue;
            int a = v[i];
            int target = -v[i];
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = v[l] + v[r];
                int b = v[l], c = v[r];
                if (sum == target) {
                    ans.push_back({a, b, c});
                    while (l < r && v[l] == b) l++;
                    while (l < r && v[r] == b) r--;
                }
                else if (sum < target) l++;
                else if (sum > target) r--;
            }
            while (i + 1 < n && a == v[i + 1]) i++;
        }
        return ans;
    }
};
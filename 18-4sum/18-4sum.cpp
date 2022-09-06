class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, long long target) {
        int N = v.size();
        vector<vector<int>> ans;
        sort(v.begin(), v.end());
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                long long t = target - v[i] - v[j];
                int l = j + 1, r = N - 1;
                while (l < r) {
                    if (v[l] + v[r] == t) {
                        ans.push_back({v[i], v[j], v[l], v[r]});
                        while (l < r && l + 1 < N && v[l] == v[l + 1]) l++;
                        while (l < r && r - 1 >= 0 && v[r] == v[r - 1]) r--;
                        l++, r--;
                    } else if (v[l] + v[r] < t) {
                        l++;
                    } else {
                        r--;
                    }
                }
                while (j + 1 < N && v[j] == v[j + 1]) j++;
            }
            while (i + 1 < N && v[i] == v[i + 1]) i++;
        }
        return ans;
    }
};
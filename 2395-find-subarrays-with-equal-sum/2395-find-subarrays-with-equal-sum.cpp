class Solution {
public:
    bool findSubarrays(vector<int>& v) {
        int n = v.size();
        for (int i = 0; i < n - 1; i++) {
            int sum = v[i] + v[i + 1];
            for (int j = i + 1; j < n - 1; j++) {
                if (v[j] + v[j + 1] == sum) return true;
            }
        }
        return false;
    }
};
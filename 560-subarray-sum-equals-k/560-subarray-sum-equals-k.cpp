class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        int ans = 0, sum = 0;
        map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < v.size(); i++) {
            sum += v[i];
            if (mp[sum - k]) {
                ans += mp[sum - k];
            }
            mp[sum]++;
        }
        return ans;
    }
};
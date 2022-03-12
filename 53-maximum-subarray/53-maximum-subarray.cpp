class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int cur_sum = 0, ans = INT_MIN;
        for(int &x: a) {
            int new_sum = cur_sum + x;
            if(new_sum > ans) ans = new_sum;
            cur_sum = new_sum;
            if(cur_sum < 0) cur_sum = 0;
        }
        return ans;
    }
};
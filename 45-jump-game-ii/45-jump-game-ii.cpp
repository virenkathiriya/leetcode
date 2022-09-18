class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReachable = 0;
        int maxIndexForThisLevel = 0;
        int ans = 0;
        int N = nums.size();
        int i = 0;
        while (maxIndexForThisLevel < N - 1) {
            maxReachable = max(maxReachable, i + nums[i]);
            if (maxIndexForThisLevel == i) { // bfs level completed
                maxIndexForThisLevel = maxReachable;
                ans++;
            }
            i++;
        }
        return ans;
    }
};
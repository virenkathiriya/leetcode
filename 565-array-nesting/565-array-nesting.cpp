class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int N = nums.size();
        int ans = 1;
        for(int i = 0; i < N; i++) {
            int cur = nums[i];
            if(cur == -1) continue;
            
            nums[i] = -1; // marking it visited
            
            int cur_len = 1;
            while(nums[cur] != -1) { // if possible to jump to next
                cur_len++; // inc length
                
                int vis = cur; 
                cur = nums[cur]; // pointer pass to next nest
                
                nums[vis] = -1;
            }
            ans = max(cur_len, ans);
        }
        return ans;
    }
};
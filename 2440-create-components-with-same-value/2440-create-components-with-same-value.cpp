class Solution {
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int N = nums.size();
        vector<vector<int>> adj(N);
        vector<int> deg(N, 0);
        
        for (auto &it: edges) {
            int u = it[0], v = it[1];
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
            deg[u]++, deg[v]++;
        }
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        for (int split = N; split >= 1; --split) 
            if (sum % split == 0 && ifPossible(adj, deg, nums, sum / split)) 
                return split - 1; 
        return 0;
    }
    
    bool ifPossible(vector<vector<int>>& adj, vector<int> deg, vector<int> nums, int target) {
        queue<int> q;
        for (int i = 0; i < nums.size(); ++i) if (deg[i] == 1) q.push(i);
        while (!q.empty()) {
            int u = q.front();
            deg[u] = 0;
            q.pop();
            for (int &v: adj[u]) {
                if (nums[u] != target) {
                    nums[v] += nums[u];
                    //if (nums[v] > target) return false;  
                } 
                deg[v]--;
                if (deg[v] == 1) q.push(v);
                if (deg[v] == 0) return nums[v] == target;
            } 
        }
        return true;
    }
};
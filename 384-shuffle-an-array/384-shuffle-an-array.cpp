class Solution {
public:
    vector<int> v, original;
    Solution(vector<int>& nums) {
        v = nums;
        original = nums;
    }
    
    vector<int> reset() {
        v = original;
        return v;
    }
    
    vector<int> shuffle() {
        if (v.size() == 1) return v;
        for (int &x: v)
            swap(x, v[rand() % v.size()]);
        return v;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
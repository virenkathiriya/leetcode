class Solution {
public:
    vector<int> pancakeSort(vector<int>& v) {
        int N = v.size();
        vector<int> ans;
        for (int i = N - 1; i >= 0; i--) {
            int x = findMax(v, i + 1);
            if (x == i) continue; 
            flip(v, ans, x + 1);
            flip(v, ans, i + 1);
        }
        return ans;
    }
    
    int findMax(vector<int> &v, int N) {
        int mx = INT_MIN, ind = -1;
        for (int i = 0; i < N; i++) {
            if (v[i] > mx) {
                mx = v[i];
                ind = i;
            }
        }
        return ind;
    }
    
    void flip(vector<int> &v, vector<int>&ans, int N) {
        ans.push_back(N);
        for (int i = 0; i < N / 2; i++) swap(v[i], v[N - 1 - i]); 
    }
};
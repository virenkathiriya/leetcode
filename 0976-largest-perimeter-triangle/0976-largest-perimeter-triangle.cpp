class Solution {
public:
    int largestPerimeter(vector<int>& v) {
        sort(v.rbegin(), v.rend());
        for (int i = 0; i < v.size() - 2; i++)
            if (v[i] < v[i + 1] + v[i + 2]) 
                return v[i] + v[i + 1] + v[i + 2];
        
        return 0;
    }
};
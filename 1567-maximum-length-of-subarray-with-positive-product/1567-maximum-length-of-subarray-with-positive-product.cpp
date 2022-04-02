class Solution {
public:
    int getMaxLen(vector<int>& v) {
        int i = 0;
        int ans = 0;
        int n = v.size();
        while (i < n) {
            while (i < n && v[i] == 0) i++;
            int ptr = i;
            int nCnt = 0;
            int start_of_subarray = ptr;
            int first_negative = -1;
            int last_negative = -1;
            // starting of non-zero subarray
            while (ptr < n && v[ptr] != 0) {
                if (v[ptr] < 0) {
                    nCnt++;
                    if (first_negative == -1) first_negative = ptr;
                    last_negative = ptr;
                } 
                ptr++;
                
                if (nCnt % 2) {
                    // atleast first_negative will be not 
                    ans = max(ans, ptr - first_negative - 1);
                    
                    if (last_negative) {
                        ans = max(ans, last_negative - first_negative);
                    }
                } else {
                    ans = max(ans, ptr - start_of_subarray);
                }
            }
            i = ptr;
        }
        return ans;
    }
};
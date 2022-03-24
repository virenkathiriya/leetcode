class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        // 3*3 square check
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                // top left point will be b[i * 3][j * 3]
                vector<int> vis(10, 0);
                for (int x = 0; x < 3; x++) {
                    for(int y = 0; y < 3; y++) {
                        char val = b[i * 3 + x][j * 3 + y];
                        if(!isdigit(val)) continue;
                        if(vis[val - '0']) {
                            return false;
                        } 
                        vis[val - '0'] = true;
                    }
                }
            }
        }
        // row check
        for(int i = 0; i < 9; ++i) {
            vector<bool> vis(10, false);
            for(int j = 0; j < 9; ++j) {
                char val = b[i][j];
                if(!isdigit(val)) continue;
                
                if(vis[val - '0']) {
                    return false;
                } 
                vis[val - '0'] = true;
            } 
        }
        
        // col check
        for(int i = 0; i < 9; ++i) {
            vector<bool> vis(10, false);
            for(int j = 0; j < 9; ++j) {
                char val = b[j][i];
                if(!isdigit(val)) continue;
                
                if(vis[val - '0']) {
                    return false;
                } 
                vis[val - '0'] = true;
            } 
        }
        
        return true;
    }
};
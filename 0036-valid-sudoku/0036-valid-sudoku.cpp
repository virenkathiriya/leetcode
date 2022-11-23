class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& g) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                vector<bool> sq(10, false);
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (isdigit(g[i * 3 + k][j * 3 + l])) {
                            if (sq[g[i * 3 + k][j * 3 + l] - '0']) {
                                return false;
                            }
                            sq[g[i * 3 + k][j * 3 + l] - '0'] = true;
                        }
                    }
                }    
            }
        }
        for (int i = 0; i < 9; i++) {
            vector<bool> row(10, false);
            for (int j = 0; j < 9; j++) {
                if (isdigit(g[i][j])) {
                    if (row[g[i][j] - '0']) {
                        return false;
                    }
                    row[g[i][j] - '0'] = true;
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            vector<bool> col(10, false);
            for (int j = 0 ; j < 9; j++) {
                if (isdigit(g[j][i])) {
                    if (col[g[j][i] - '0']) {
                        return false;
                    }
                    col[g[j][i] - '0'] = true;
                }
            }
        }
        return true;
    }
};
class Solution {
private:
    struct TrieNode {
        char key;
        vector<TrieNode*> alpha;
        bool isEndOfString;
        int size = 0;
        TrieNode(char c) : key(c){
            alpha.resize(26, NULL);
            isEndOfString = false;
        }
    };
public:
    string longestCommonPrefix(vector<string>& st) {
        TrieNode *root = new TrieNode(' ');
        for (string s: st) {
            int n = s.size();
            if (n == 0) return "";
            TrieNode *cur = root;
            for (int i = 0 ; i < n; i++) {
                int x = s[i] - 'a';
                if (!cur -> alpha[x]) {
                    cur -> alpha[x] = new TrieNode(s[i]);
                    cur -> size = cur -> size + 1;
                    if (cur -> size > 1) break;
                } 
                cur = cur -> alpha[x];
                if (i == n - 1) cur -> isEndOfString = true;
            }
        }
        if (root -> size > 1) return "";
        TrieNode *ptr = root -> alpha[st[0][0] - 'a'];
        string ans;
        
        while (ptr) {
            ans += ptr -> key;
            if (ptr -> size > 1 || ptr -> isEndOfString) return ans;
            for (int i = 0; i < 26; i++) {
                if (ptr -> alpha[i]) {
                    ptr = ptr -> alpha[i];
                    break;
                }
            }
        }
        return ans;
    }
};
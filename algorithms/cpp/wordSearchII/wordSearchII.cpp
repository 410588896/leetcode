/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
struct Trie {
    string word;
    unordered_map<char, Trie*> child;
    Trie() {
        this->word = "";
    }
};

void insert(Trie* node, const string &word) {
    for (auto ch : word) {
        if (!node->child.count(ch)) {
            node->child[ch] = new Trie();
        }
        node = node->child[ch];
    }
    node->word = word;
}

class Solution {
private:
    bool dfs(Trie *node, vector<vector<char>>& board, int x, int y, set<string> &res) {
        char ch = board[x][y];
        if (!node->child.count(ch)) {
            return false;
        }
        node = node->child[ch];
        if (node->word.size() > 0) {
            res.insert(node->word);
        }
        board[x][y] = '#';
        for (int i = 0; i < 4; i++) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
                if (board[nx][ny] != '#') {
                    dfs(node, board, nx, ny, res);
                }
            }
        }
        board[x][y] = ch;
        return true;
    }
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie * root = new Trie();
        for (auto word : words) {
            insert(root, word);
        }
        vector<string> res;
        set<string> s;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(root, board, i, j, s); 
            }
        }
        for (auto word : s) {
            res.push_back(word);
        }
        return res;
    }
};
// @lc code=end



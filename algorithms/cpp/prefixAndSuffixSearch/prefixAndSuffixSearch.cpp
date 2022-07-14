/*
 * @lc app=leetcode.cn id=745 lang=cpp
 *
 * [745] 前缀和后缀搜索
 */

// @lc code=start
struct Trie {
    unordered_map<char, Trie *> child;
    vector<int> index;
};

class WordFilter {
private:
    Trie *preTrie;
    Trie *postTrie;
    vector<int> emptyVec;//设置了空vector
public:
    WordFilter(vector<string>& words) {
        preTrie = new Trie();
        postTrie = new Trie();
        for (int i = 0; i < words.size(); i++) {
            Trie* preNode = preTrie;
            Trie* postNode = postTrie;
            int wordLen = words[i].size();
            for (int j = 0; j < wordLen; j++) {
                if (!preNode->child.count(words[i][j])) {
                    preNode->child[words[i][j]] = new Trie();
                }
                preNode = preNode->child[words[i][j]];
                preNode->index.push_back(i);
                if (!postNode->child.count(words[i][wordLen - j - 1])) {
                    postNode->child[words[i][wordLen - j - 1]] = new Trie();
                }
                postNode = postNode->child[words[i][wordLen - j - 1]];
                postNode->index.push_back(i);
            }
        }
    }

    vector<int> &search(string word, Trie *node) {
        for (auto ch : word) {
            if (!node->child.count(ch)) {
                return emptyVec;
            }
            node = node->child[ch];
        }
        return node->index;
    }
    
    int f(string pref, string suff) {
        reverse(suff.begin(), suff.end());
        vector<int> &prefList = search(pref, preTrie);
        vector<int> &suffList = search(suff, postTrie);
        if (prefList.size() == 0 || suffList.size() == 0) {
            return -1;
        }
        int i = prefList.size() - 1;
        int j = suffList.size() - 1;
        while (i >= 0 && j >= 0) {
            if (prefList[i] == suffList[j]) {
                return prefList[i];
            } else if (prefList[i] < suffList[j]) {
                j--;
            } else {
                i--;
            }
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
// @lc code=end



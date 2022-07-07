/*
 * @lc app=leetcode.cn id=648 lang=cpp
 *
 * [648] 单词替换
 */

// @lc code=start
struct Trie {
    unordered_map<char, Trie*> children;
};
class Solution {
private:
    vector<string> split(string &str, char ch) {
        int pos = 0;
        int start = 0;
        vector<string> ret;
        while (pos < str.size()) {
            while (pos < str.size() && str[pos] == ch) {
                pos++;
            }
            start = pos;
            while (pos < str.size() && str[pos] != ch) {
                pos++;
            }
            if (start < str.size()) {
                ret.emplace_back(str.substr(start, pos - start));
            }
        }
        return ret;
    }
    string findRoot(string &word, Trie *trie) {
        string root;
        for (auto c : word) {
            if (trie->children.count('#')) {
                return root;
            }
            if (!trie->children.count(c)) {
                return word;
            }
            root.push_back(c);
            trie = trie->children[c];
        }
        return root;
    }

public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie *trie = new Trie();
        for (auto word : dictionary) {
            Trie *cur = trie;
            for (auto c : word) {
                if (!cur->children.count(c)) {
                    cur->children[c] = new Trie();
                }
                cur = cur->children[c];
            }
            cur->children['#'] = new Trie();
        }
        vector<string> words = split(sentence, ' ');
        for (auto &word : words) {
            word = findRoot(word, trie);
        }
        string res;
        for (int i = 0; i < words.size() - 1; i++) {
            res.append(words[i]);
            res.append(" ");
        }
        res.append(words.back());
        return res;
    }
};
// @lc code=end



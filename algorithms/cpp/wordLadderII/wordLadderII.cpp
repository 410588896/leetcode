/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

/****************************************
* 
* Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
* 
* Only one letter can be changed at a time
* Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
* Note:
* 
* Return an empty list if there is no such transformation sequence.
* All words have the same length.
* All words contain only lowercase alphabetic characters.
* You may assume no duplicates in the word list.
* You may assume beginWord and endWord are non-empty and are not the same.
* Example 1:
* 
* Input:
* beginWord = "hit",
* endWord = "cog",
* wordList = ["hot","dot","dog","lot","log","cog"]
* 
* Output:
* [
*   ["hit","hot","dot","dog","cog"],
*   ["hit","hot","lot","log","cog"]
* ]
* Example 2:
* 
* Input:
* beginWord = "hit"
* endWord = "cog"
* wordList = ["hot","dot","dog","lot","log"]
* 
* Output: []
* 
* Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
* 
****************************************/

// @lc code=start
class Solution {
private:
    unordered_map<string, int> wordID;
    vector<string> IDWord;
    vector<vector<int>> edges;
    bool transformCheck(const string &word1, const string &word2) {
        int differences = 0;
        for (int i = 0; i < word1.size() && differences < 2; i++) {
            if (word1[i] != word2[i]) ++differences;
        }
        return differences == 1;
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int id = 0;
        for (const string &word : wordList) {
            if (!wordID.count(word)) {
                wordID[word] = id++;
                IDWord.push_back(word);
            }
        }
        if (!wordID.count(endWord)) return {};
        if (!wordID.count(beginWord)) {
            wordID[beginWord] = id++;
            IDWord.push_back(beginWord);
        }
        edges.resize(IDWord.size());
        for (int i = 0; i < IDWord.size(); i++) {
            for (int j = i + 1; j < IDWord.size(); j++) {
                if (transformCheck(IDWord[i], IDWord[j])) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        const int dest = wordID[endWord];
        vector<vector<string> > res;
        queue<vector<int> > q;
        vector<int> cost(id, INT_MAX);
        q.push(vector<int>{wordID[beginWord]});
        cost[wordID[beginWord]] = 0;
        while (!q.empty()) {
            vector<int> now = q.front();
            q.pop();
            int last = now.back();
            if (last == dest) {
                vector<string> tmp;
                for (auto idx : now) {
                    tmp.push_back(IDWord[idx]);
                }
                res.push_back(tmp);
            } else {
                for (int i = 0; i < edges[last].size(); i++) {
                    int to = edges[last][i];
                    if (cost[last] + 1 <= cost[to]) {
                        cost[to] = cost[last] + 1;
                        vector<int> tmp(now);
                        tmp.push_back(to);
                        q.push(tmp);
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end



/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

/********************************
* 
* Given two words beginWord and endWord, and a dictionary wordList, return the length of the shortest transformation sequence from beginWord to endWord, such that:
* 
* Only one letter can be changed at a time.
* Each transformed word must exist in the word list.
* Return 0 if there is no such transformation sequence.
* 
*  
* 
* Example 1:
* 
* Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
* Output: 5
* Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog", return its length 5.
* Example 2:
* 
* Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
* Output: 0
* Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*  
* 
* Constraints:
* 
* 1 <= beginWord.length <= 100
* endWord.length == beginWord.length
* 1 <= wordList.length <= 5000
* wordList[i].length == beginWord.length
* beginWord, endWord, and wordList[i] consist of lowercase English letters.
* beginWord != endWord
* All the strings in wordList are unique.
* 
********************************/

// @lc code=start
class Solution {
private:
    unordered_map<string, int> wordID;
    vector<string> IDWord;
    vector<vector<int> > edges;
    int id = 0;
    bool transformCheck(const string &word1, const string &word2) {
        int dis = 0;
        for (int i = 0; i < word1.size() && dis < 2; i++) {
            if (word1[i] != word2[i]) dis++;
        }
        return dis == 1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for (const string &word : wordList) {
            if (!wordID.count(word)) {
                wordID[word] = id++;
                IDWord.push_back(word);
            }
        }
        if (!wordID.count(beginWord)) {
            wordID[beginWord] = id++;
            IDWord.push_back(beginWord);
        }
        if (!wordID.count(endWord)) return 0;
        edges.resize(id);
        for (int i = 0; i < IDWord.size(); i++) {
            for (int j = i + 1; j < IDWord.size(); j++) {
                if (transformCheck(IDWord[i], IDWord[j])) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        vector<int> path(id, INT_MAX);
        path[wordID[beginWord]] = 0;
        int beginID = wordID[beginWord], endID = wordID[endWord];
        queue<int> q;
        q.push(beginID);
        while (q.size()) {
            int x = q.front();
            q.pop();
            if (x == endID) {
                return path[endID] + 1;
            } 
            for (int & it : edges[x]) {
                if (path[it] >= path[x] + 1) {
                    path[it] = path[x] + 1;
                    q.push(it);
                }
            }
        }
        return 0;
    }
};
// @lc code=end



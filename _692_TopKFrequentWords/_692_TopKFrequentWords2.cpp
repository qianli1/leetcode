#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

struct TrieNode {
  vector<TrieNode*> children;
  string word;
  TrieNode() {
    this->children.resize(26);
    this->word = "";
  }
};

class _692_TopKFrequentWords2 {
    /**
    * 692. Top K Frequent Words
    * Given a non-empty list of words, return the k most frequent elements.

    Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with 
    the lower alphabetical order comes first.

    Example 1:
    Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
    Output: ["i", "love"]
    Explanation: "i" and "love" are the two most frequent words.
        Note that "i" comes before "love" due to a lower alphabetical order.
    Example 2:
    Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
    Output: ["the", "is", "sunny", "day"]
    Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
        with the number of occurrence being 4, 3, 2 and 1 respectively.
    Note:
    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Input words contain only lowercase letters.

    Time: O(n)
    Space: O(n)
    */
 
 public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    map<string, int> mp;
    for (string word : words) {
        mp[word]++;
    }
    
    vector<TrieNode*> count(words.size() + 1);
    for (auto& v: mp) {
        int freq = v.second;
        if (count[freq] == NULL) {
            count[freq] = new TrieNode();
        }
        addWord(count[freq], v.first);
    }
    vector<string> res;
    for (int f = count.size() - 1; f >= 1 && res.size() < k; f--) {
        if (count[f] == NULL) {
            continue;
        }
        getWords(count[f], res, k);
    }
    return res;
  }

  void getWords(TrieNode* node, vector<string>& list, int k) {
    if (node == NULL) {
        return;
    }
    if (node->word != "") {
        list.push_back(node->word);
    }
    if (list.size() == k) {
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (node->children[i] != NULL) {
            getWords(node->children[i], list, k);
        }
    }
  }

  bool addWord(TrieNode* root, string word) {
    TrieNode* cur = root;
    for (char c : word) {
        if (cur->children[c - 'a'] == NULL) {
            cur->children[c - 'a'] = new TrieNode();
        }
        cur = cur->children[c - 'a'];
    }
    cur->word = word;
    return true;
  }
};





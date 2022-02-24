#include <vector>
#include <string>
#include <unordered_set>

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
  TrieNode *children[26];
  string word;

  TrieNode() {
    word = "";
    for (int i = 0; i < 26; i++) {
        children[i] = NULL;
    }
  }
};

class _720_LongestWordinDictionary {
    /**
    * 720. Longest Word in Dictionary
    * Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one 
    * character at a time by other words in words. If there is more than one possible answer, return the longest word with 
    * the smallest lexicographical order.

    If there is no answer, return the empty string.
    Example 1:
    Input: 
    words = ["w","wo","wor","worl", "world"]
    Output: "world"
    Explanation: 
    The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
    Example 2:
    Input: 
    words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
    Output: "apple"
    Explanation: 
    Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller 
    than "apply".

    time : O(n);
    space : O(n);
    */
 
 public:
  string longestWord(vector<string>& words) {
    sort(words.begin(), words.end());
    unordered_set<string> s;
    string res = "";
    
    for (string word : words) {
        if (word.size() == 1 || s.count(word.substr(0, word.size() - 1))) {
            res = word.size() > res.size() ? word : res;
            s.insert(word);
        }
    }
    return res;
  }

  TrieNode* root;
    
  void insert(string word) {
    TrieNode* node = root;
    for (int i = 0; i < word.size(); i++) {
        int j = word[i] - 'a';
        if (node->children[j] == NULL) {
            node->children[j] = new TrieNode();
        }
        node = node->children[j];
    }
    node->word = word;
  }

  string find(TrieNode* root) {
    string res = root->word;
    for (TrieNode* child : root->children) {
        if (child == NULL || child->word == "") {
            continue;
        }
        string word = find(child);
        if (word.size() > res.size()) {
            res = word;
        }
    }
    return res;
  }

  string longestWord2(vector<string>& words) {
    root = new TrieNode();
    for (string word : words) {
        insert(word);
    }
    return find(root);
  }
};





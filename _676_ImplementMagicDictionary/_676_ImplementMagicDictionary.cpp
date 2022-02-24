#include <vector>
#include <string>
#include <unordered_map>
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

class _676_ImplementMagicDictionary {
    /**
    * 676. Implement Magic Dictionary
    * We want to implement a data structure that will be intialized with a list of distinct strings, then you will be given 
    * another string and you should find if you can change exactly one letter of this string to match any string in the 
    * data structure.

    Implement the MagicDictionary class:

    MagicDictionary() Initializes the object.
    void buildDict(String[] dictionary) Sets the data structure with an array of distinct strings dictionary.
    bool search(String searchWord) Returns true if you can change exactly one character in word to match any string in the data 
    structure, otherwise returns false.

    Example 1:

    Input
    ["MagicDictionary", "buildDict", "search", "search", "search", "search"]
    [[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
    Output
    [null, null, false, true, false, false]

    Explanation
    MagicDictionary magicDictionary = new MagicDictionary();
    magicDictionary.buildDict(["hello", "leetcode"]);
    magicDictionary.search("hello"); // return False
    magicDictionary.search("hhllo"); // We can change the second 'h' to 'e' to match "hello" so we return True
    magicDictionary.search("hell"); // return False
    magicDictionary.search("leetcoded"); // return False

    */
 
 private:
  unordered_map<int, unordered_set<string>> mp;
 public:
  /** Initialize your data structure here. */
  MagicDictionary() {
    
  }

  /** Build a dictionary through a list of words */
  void buildDict(vector<string> dict) {
    for (string word : dict) {
        int len = word.size();
        mp[len].insert(word);
    }
  }

  /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
  bool search(string word) {
    int len = word.size();
    if (!mp.count(len)) {
        return false;
    }
    for (string s : mp[len]) {
        int count = 0;
        for (int i = 0; i < len; i++) {
            if (word[i] != s[i]) {
                count++;
            }
        }
        if (count == 1) {
            return true;
        }
    }
    return false;
  }
};





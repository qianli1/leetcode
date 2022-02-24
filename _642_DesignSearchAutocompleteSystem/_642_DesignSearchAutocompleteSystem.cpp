#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class TrieNode {
 public:
  vector<string> top3;
  vector<TrieNode*> children;

  TrieNode() {
    this->children.resize(27);
  }

  void add(unordered_map<string, int>& mp, string sentence, int start) {
    if (find(top3.begin(), top3.end(), sentence) == top3.end()) {
        top3.push_back(sentence);
    }
    sort(top3.begin(), top3.end(), [&](string& a, string& b) {
        if (mp[a] == mp[b]) {
            return a < b;
        }
        return (mp[b] - mp[a] < 0);
    });
    if (top3.size() > 3) {
        top3.pop_back();
    }
    if (start == sentence.size()) {
        return;
    }
    getNext(sentence[start])->add(mp, sentence, start + 1);
  }

  TrieNode* getNext(char ch) {
    int index = ch == ' ' ? 26 : ch - 'a';
    if (children[index] == NULL) {
        children[index] = new TrieNode();
    }
    return children[index];
  }
}; 

class _642_DesignSearchAutocompleteSystem {
    /**
    * 642. Design Search Autocomplete System
    * Design a search autocomplete system for a search engine. Users may input a sentence (at least one word and end with a special 
    * character '#'). For each character they type except '#', you need to return the top 3 historical hot sentences that have prefix 
    * the same as the part of sentence already typed. Here are the specific rules:

    The hot degree for a sentence is defined as the number of times a user typed the exactly same sentence before.
    The returned top 3 hot sentences should be sorted by hot degree (The first is the hottest one). If several sentences have the same 
    degree of hot, you need to use ASCII-code order (smaller one appears first).
    If less than 3 hot sentences exist, then just return as many as you can.
    When the input is a special character, it means the sentence ends, and in this case, you need to return an empty list.
    Your job is to implement the following functions:

    The constructor function:

    AutocompleteSystem(String[] sentences, int[] times): This is the constructor. The input is historical data. Sentences is a string 
    array consists of previously typed sentences. Times is the corresponding times a sentence has been typed. Your system should record 
    these historical data.

    Now, the user wants to input a new sentence. The following function will provide the next character the user types:

    List<String> input(char c): The input c is the next character typed by the user. The character will only be lower-case letters ('a' 
    to 'z'), blank space (' ') or a special character ('#'). Also, the previously typed sentence should be recorded in your system. The 
    output will be the top 3 historical hot sentences that have prefix the same as the part of sentence already typed.

    
    Example:
    Operation: AutocompleteSystem(["i love you", "island","ironman", "i love leetcode"], [5,3,2,2])
    The system have already tracked down the following sentences and their corresponding times:
    "i love you" : 5 times
    "island" : 3 times
    "ironman" : 2 times
    "i love leetcode" : 2 times
    Now, the user begins another search:

    Operation: input('i')
    Output: ["i love you", "island","i love leetcode"]
    Explanation:
    There are four sentences that have prefix "i". Among them, "ironman" and "i love leetcode" have same hot degree. Since ' ' has ASCII 
    code 32 and 'r' has ASCII code 114, "i love leetcode" should be in front of "ironman". Also we only need to output top 3 hot sentences, 
    so "ironman" will be ignored.

    Operation: input(' ')
    Output: ["i love you","i love leetcode"]
    Explanation:
    There are only two sentences that have prefix "i ".

    Operation: input('a')
    Output: []
    Explanation:
    There are no sentences that have prefix "i a".

    Operation: input('#')
    Output: []
    Explanation:
    The user finished the input, the sentence "i a" should be saved as a historical sentence in system. And the following input will be 
    counted as a new search.
        
    */
 
 private:
  TrieNode* root;
  TrieNode* cur;
  unordered_map<string, int> mp;
  string sb;

 public:
  AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
    this->root = new TrieNode();
    this->cur = root;
    
    for (int i = 0; i < sentences.size(); i++) {
        mp[sentences[i]] = times[i];
        root->add(mp, sentences[i], 0);
    }
  }

  vector<string> input(char c) {
    vector<string> res;
    if (c == '#') {
        string str = sb;
        mp[str]++;
        root->add(mp, str, 0);
        sb.clear();
        cur = root;
        return res;
    }
    sb += c;
    cur = cur->getNext(c);
    return cur->top3;
  }
};





#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _336_PalindromePairs {
    /**
    * 336. Palindrome Pairs
    * Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the 
    * concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

    Example 1:

    Input: ["abcd","dcba","lls","s","sssll"]
    Output: [[0,1],[1,0],[3,2],[2,4]] 
    Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
    Example 2:

    Input: ["bat","tab","cat"]
    Output: [[0,1],[1,0]] 
    Explanation: The palindromes are ["battab","tabbat"]

    time : O(n * k^2);
    space : O(n);
    */
 
 public:
  vector<vector<int>> palindromePairs(vector<string>& words) {
    vector<vector<int>> res;
    if (words.empty() || words.size() < 2) return res;
    unordered_map<string, int> map;
    for (int i = 0; i < words.size(); i++) {
        map[words[i]] = i;
    }
    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j <= words[i].size(); j++) {
            string str1 = words[i].substr(0, j);
            string str2 = words[i].substr(j);
            if (isPalindrome(str1)) {
                string str2rvs = str2;
                reverse(str2rvs.begin(), str2rvs.end());
                if (map.count(str2rvs) && map[str2rvs] != i) {
                    res.push_back({map[str2rvs], i});
                }
            }
            if (str2.size() != 0 && isPalindrome(str2)) {
                string str1rvs = str1;
                reverse(str1rvs.begin(), str1rvs.end());
                if (map.count(str1rvs) && map[str1rvs] != i) {
                    res.push_back({i, map[str1rvs]});
                }
            }
        }
    }
    return res;            
  }
                
  bool isPalindrome(string& s) {
    int left = 0;
    int right = s.size() - 1;
    while (left <= right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
  }
};





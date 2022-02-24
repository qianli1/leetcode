#include <vector>
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

class _748_ShortestCompletingWord {
    /**
    * 748. Shortest Completing Word
    * Find the minimum length word from a given dictionary words, which has all the letters from the string licensePlate. 
    * Such a word is said to complete the given string licensePlate

    Here, for letters we ignore case. For example, "P" on the licensePlate still matches "p" on the word.

    It is guaranteed an answer exists. If there are multiple answers, return the one that occurs first in the array.

    The license plate might have the same letter occurring multiple times. For example, given a licensePlate of "PP", the word 
    "pair" does not complete the licensePlate, but the word "supper" does.

    Example 1:
    Input: licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
    Output: "steps"
    Explanation: The smallest length word that contains the letters "S", "P", "S", and "T".
    Note that the answer is not "step", because the letter "s" must occur in the word twice.
    Also note that we ignored case for the purposes of comparing whether a letter exists in the word.
    Example 2:
    Input: licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
    Output: "pest"
    Explanation: There are 3 smallest length words that contains the letters "s".
    We return the one that occurred first.

    time : O(n);
    space : O(1);
    */
 
 public:
  string shortestCompletingWord(string licensePlate, vector<string>& words) {
    vector<int> count(26);
    int total = 0;
    for (char c : licensePlate) {
        c = tolower(c);
        if ('a' <= c && c <= 'z') {
            count[c - 'a']++;
            total++;
        }
    }
    
    string res = "";
    for (string word : words) {
        int n = total;
        vector<int> cnt = count;
        for (char c : word) {
            if (cnt[c - 'a']-- > 0) {
                n--;
            }
        }
        if (n == 0 && (res.size() == 0 || word.size() < res.size())) {
            res = word;
        }
    }
    return res;
  }

  string shortestCompletingWord2(string licensePlate, vector<string>& words) {
    vector<int> target = count(licensePlate);
    string res = "";
    for (string word : words) {
        if ((word.size() < res.size() || res.size() == 0) &&
            compare(count(word), target)) {
            res = word;
        }
    }
    return res;
  }

  bool compare(vector<int> count1, vector<int> count2) {
    for (int i = 0; i < 26; i++) {
        if (count1[i] < count2[i]) {
            return false;
        }
    }
    return true;
  }

  vector<int> count(string licensePlate) {
    vector<int> count(26);
    int total = 0;
    for (char c : licensePlate) {
        c = tolower(c);
        if ('a' <= c && c <= 'z') {
            count[c - 'a']++;
        }
    }
    return count;
  }
};





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

class _616_AddBoldTaginString {
    /**
    * 616. Add Bold Tag in String
    * Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings 
    * in s that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. 
    * Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.
    Example 1:

    Input: 
    s = "abcxyz123"
    dict = ["abc","123"]
    Output:
    "<b>abc</b>xyz<b>123</b>"
 
    Example 2:

    Input: 
    s = "aaabbcc"
    dict = ["aaa","aab","bc"]
    Output:
    "<b>aaabbc</b>c"

    time : O(m * n);
    space : O(n);
    */
 
 public:
  string addBoldTag(string s, vector<string>& dict) {
    vector<bool> bold(s.size());
    for (string word : dict) {
        int start = 0;
        while (start != string::npos) {
            start = s.find(word, start);
            if (start == string::npos) {
                break;
            }
            int end = start + word.size();
            for (int i = start; i < end; i++) {
                bold[i] = true;
            }
            start++;
        }
    }
    
    string sb;
    for (int i = 0; i < s.size(); i++) {
        if (bold[i] && (i == 0 || !bold[i - 1])) {
            sb += "<b>";
        }
        sb += s[i];
        if (bold[i] && (i == s.size() - 1 || !bold[i + 1])) {
            sb += "</b>";
        }
    }
    return sb;
  }

  string addBoldTag2(string s, vector<string>& dict) {
    vector<bool> bold(s.size());
    for (int i = 0, end = 0; i < s.size(); i++) {
        for (string word : dict) {
            if (s.substr(i).find(word) == 0) {
                end = max(end, i + (int)word.size());
            }
        }
        bold[i] = end > i;
    }
    string res;
    for (int i = 0; i < s.size(); i++) {
        if (!bold[i]) {
            res += s[i];
            continue;
        }
        int j = i;
        while (j < s.size() && bold[j]) {
            j++;
        }
        res += "<b>";
        res += s.substr(i, j - i);
        res += "</b>";
        i = j - 1;
    }
    return res;
  }
};





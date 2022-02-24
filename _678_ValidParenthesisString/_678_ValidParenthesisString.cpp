#include <vector>
#include <string>
#include <stack>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _678_ValidParenthesisString {
    /**
    * 678. Valid Parenthesis String
    * Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. 
    * We define the validity of a string by these rules:

    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
    An empty string is also valid.
    Example 1:
    Input: "()"
    Output: True
    Example 2:
    Input: "(*)"
    Output: True
    Example 3:
    Input: "(*))"
    Output: True

    Time: O(n)
    Space: O(1)
    */
 
 public:
  bool checkValidString(string s) {
    int low = 0, high = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == '(') {
            high++;
            low++;
        } else if (c == ')') {
            high--;
            low = max(low - 1, 0);
        } else {
            high++;
            low = max(low - 1, 0);
        }
        if (high < 0) {
            return false;
        }
    }
    return low == 0;
  }

  bool checkValidString2(string s) {
    stack<char> st;
    int count = 0;
    for (char c : s) {
        if (c == '(') {     
            st.push(c);
        } else {
            if (c == ')' && !st.empty()) {  //()
                st.pop();
            } else if (c == ')' && count > 0) { //*)
                count--;
            } else if (c == ')') { // )
                return false;
            } else {
                count++;
                if (!st.empty()) {  // (*))
                    st.pop();
                    count++;
                }
            }
        }
    }
    return st.empty();
  }
};






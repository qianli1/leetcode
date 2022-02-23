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

class _402_RemoveKDigits {
    /**
    * 402. Remove K Digits
    * Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

    Note:
    The length of num is less than 10002 and will be ≥ k.
    The given num does not contain any leading zero.
    Example 1:

    Input: num = "1432219", k = 3
    Output: "1219"
    Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
    Example 2:

    Input: num = "10200", k = 1
    Output: "200"
    Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
    Example 3:

    Input: num = "10", k = 2
    Output: "0"
    Explanation: Remove all the digits from the number and it is left with nothing which is 0.

    time : O(n);
    space : O(n);
    */
 
 public:
  string removeKdigits(string num, int k) {
    if (k == num.size()) {
        return "0";
    }
    stack<char> st;
    for (int i = 0; i < num.size(); i++) {
        while (k > 0 && !st.empty() && st.top() > num[i]) {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    while (k > 0) {
        st.pop();
        k--;
    }
    string sb;
    while (!st.empty()) {
        sb += st.top();
        st.pop();
    }
    reverse(sb.begin(), sb.end());
    
    int res = 0;
    while (res < sb.size() && sb[res] == '0') {
        res++;
    }
    return res == sb.size() ? "0" : sb.substr(res);
  }
};





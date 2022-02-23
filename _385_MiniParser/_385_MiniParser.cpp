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

class NestedInteger {
 public:
  // Constructor initializes an empty nested list.
  NestedInteger();

  // Constructor initializes a single integer.
  NestedInteger(int value);

  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const;

  // Set this NestedInteger to hold a single integer.
  void setInteger(int value);

  // Set this NestedInteger to hold a nested list and adds a nested integer to it.
  void add(const NestedInteger &ni);

  // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
 };

class _385_MiniParser {
    /**
    * 385. Mini Parser
    * Given a nested list of integers represented as a string, implement a parser to deserialize it.

    Each element is either an integer, or a list -- whose elements may also be integers or other lists.

    Note: You may assume that the string is well-formed:

    String is non-empty.
    String does not contain white spaces.
    String contains only digits 0-9, [, - ,, ].
    

    Example 1:

    Given s = "324",

    You should return a NestedInteger object which contains a single integer 324.
    

    Example 2:

    Given s = "[123,[456,[789]]]",

    Return a NestedInteger object containing a nested list with 2 elements:

    1. An integer containing value 123.
    2. A nested list containing two elements:
        i.  An integer containing value 456.
        ii. A nested list with one element:
            a. An integer containing value 789.

    time : O(n);
    space : O(n);
    */

public:
  NestedInteger deserialize(string s) {
    if (s[0] != '[') {
        return NestedInteger(stoi(s));
    }
    stack<NestedInteger> st;
    NestedInteger res;
    st.push(res);
    int start = 1;
    for (int i = 1; i < s.size(); i++) {
        char c = s[i];
        if (c == '[') {
            NestedInteger nested;
            st.push(nested);
            start = i + 1;
        } else if (c == ',' || c == ']') {
            if (start < i ) {
                int val = stoi(s.substr(start, i - start));
                NestedInteger temp = NestedInteger(val);
                st.top().add(temp);
            }
            start = i + 1;
            if (c == ']') {
                NestedInteger ni1 = st.top();
                if (st.size() == 1)
                    return ni1;
                st.pop();
                st.top().add(ni1);
            }
        }
    }
    return res;
  }
};





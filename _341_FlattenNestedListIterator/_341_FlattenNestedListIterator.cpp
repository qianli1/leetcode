#include <vector>
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

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
 public:
  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};



class _341_FlattenNestedListIterator {
    /**
    * 341. Flatten Nested List Iterator
    * Given a nested list of integers, implement an iterator to flatten it.

    Each element is either an integer, or a list -- whose elements may also be integers or other lists.

    Example 1:

    Input: [[1,1],2,[1,1]]
    Output: [1,1,2,1,1]
    Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,1,2,1,1].
    Example 2:

    Input: [1,[4,[6]]]
    Output: [1,4,6]
    Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,4,6].

    time : O(n);
    space : O(n);
    */
 
 private:
  stack<NestedInteger> st_;
    
 public:
  _341_FlattenNestedListIterator (vector<NestedInteger> &nestedList) {
    for (int i = nestedList.size() - 1; i >= 0; i--) {
        st_.push(nestedList[i]);
    }
    
  }

  int next() {
    NestedInteger nt = st_.top();
    st_.pop();
    return nt.getInteger();
  }

  bool hasNext() {
    while (!st_.empty()) {
        NestedInteger cur = st_.top();
        if (cur.isInteger()) {
            return true;
        }
        st_.pop();
        for (int i = cur.getList().size() - 1; i >= 0; i--) {
            st_.push(cur.getList()[i]);
        }
    }
    return false;
  }
};





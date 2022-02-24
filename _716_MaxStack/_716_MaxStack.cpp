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

class _716_MaxStack {
    /**
    * 716. Max Stack
    * Design a max stack that supports push, pop, top, peekMax and popMax.

    push(x) -- Push element x onto stack.
    pop() -- Remove the element on top of the stack and return it.
    top() -- Get the element on the top.
    peekMax() -- Retrieve the maximum element in the stack.
    popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
    Example 1:
    MaxStack stack = new MaxStack();
    stack.push(5); 
    stack.push(1);
    stack.push(5);
    stack.top(); -> 5
    stack.popMax(); -> 5
    stack.top(); -> 1
    stack.peekMax(); -> 5
    stack.pop(); -> 1
    stack.top(); -> 5

    time : O(n);
    space : O(n);
    */
 
 private: 
  stack<int> st;
  stack<int> maxSt;

 public:
  /** initialize your data structure here. */
  MaxStack() {
    
  }

  void push(int x) {
    int maximum = maxSt.empty() ? x : maxSt.top();
    maxSt.push(maximum > x ? maximum : x);
    st.push(x);
  }

  int pop() {
    maxSt.pop();
    int t = st.top();
    st.pop();
    return t;
  }

  int top() {
    return st.top();
  }

  int peekMax() {
    return maxSt.top();
  }

  int popMax() {
    int maximum = peekMax();
    
    stack<int> temp;
    while (top() != maximum) {
        temp.push(pop());
    }
    pop();
    while (!temp.empty()) {
        push(temp.top());
        temp.pop();
    }
    return maximum;
  }
};





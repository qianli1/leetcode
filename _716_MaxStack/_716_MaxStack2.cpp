#include <map>
#include <vector>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

struct LinkListNode {
  int val;
  LinkListNode* next;
  LinkListNode* prev;

  LinkListNode(int val) {
    this->val = val;
    this->next = NULL;
    this->prev = NULL;
  }
};

class _716_MaxStack2 {
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

    */
 
 private:
  LinkListNode* head;
  map<int, vector<LinkListNode*>> mp;

 public:
  /** initialize your data structure here. */
  MaxStack() {
    head = new LinkListNode(0);
    head->next = head->prev = head;
  }

  void push(int x) {
    LinkListNode* node = new LinkListNode(x);
    node->next = head;
    node->prev = head->prev;
    head->prev->next = node;
    head->prev = node;
    mp[x].push_back(node);

  }


  int pop() {
    LinkListNode* tail = head->prev;
    if (tail == head) {
        return 0;
    }
    deleteNode(tail);
    mp[tail->val].pop_back();
    if (mp[tail->val].empty()) {
        mp.erase(tail->val);
    }
    return tail->val;
  }

  int top() {
    return head->prev->val;
  }

  int peekMax() {
    return mp.rbegin()->first;
  }

  int popMax() {
    int maximum = peekMax();
    LinkListNode* node = mp[maximum].back();
    mp[maximum].pop_back();
    deleteNode(node);
    if (mp[maximum].empty()) {
        mp.erase(maximum);
    }
    return maximum;
  }

  void deleteNode(LinkListNode* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }
};





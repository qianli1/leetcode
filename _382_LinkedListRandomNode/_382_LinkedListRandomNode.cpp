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

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class _382_LinkedListRandomNode {
    /**
    * 382. Linked List Random Node
    * Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

    Follow up:
    What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?

    Example:

    // Init a singly linked list [1,2,3].
    ListNode head = new ListNode(1);
    head.next = new ListNode(2);
    head.next.next = new ListNode(3);
    Solution solution = new Solution(head);

    // getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
    solution.getRandom();

    time : O(n);
    space : O(1);
    */
 private:
  ListNode* head;
    
 public:
  /** @param head The linked list's head.
    Note that the head is guaranteed to be not null, so it contains at least one node. */
  LinkedListRandomNode(ListNode* head) {
    this->head = head;
  }

  /** Returns a random node's value. */
  int getRandom() {
    ListNode* tmp = head;
    int res = tmp->val;
    int i = 1;
    while (tmp->next) {
        tmp = tmp->next;
        if (rand() % (++i) == 0) {
            res = tmp->val;
        } 
    }
    return res;
  }
};





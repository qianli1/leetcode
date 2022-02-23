#include <cstddef>
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

class _369_PlusOneLinkedList {
    /**
    * 369. Plus One Linked List
    * Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.

    You may assume the integer do not contain any leading zero, except the number 0 itself.

    The digits are stored such that the most significant digit is at the head of the list.

    Example :

    Input: [1,2,3]
    Output: [1,2,4]

    time : O(n);
    space : O(1);
    */
 
 public:
  ListNode* plusOne(ListNode* head) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode* i = dummy;
    ListNode* j = dummy;
    
    while (j->next != NULL) {
        j = j->next;
        if (j->val != 9) i = j;
    }
    i->val++;
    i = i->next;
    while (i != NULL) {
        i->val = 0;
        i = i->next;
    }
    if (dummy->val == 0) return dummy->next;
    return dummy;
  }

  ListNode* plusOne2(ListNode* head) {
    head = reverse(head);
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* cur = dummy;
    int carry = 1;
    while (carry > 0 || cur->next) {
        if (cur->next) {
            cur = cur->next;
            carry += cur->val;
            cur->val = carry % 10;
            carry /= 10;
        } else {
            cur->next = new ListNode(carry);
            cur = cur->next;
            carry = 0;
        }
    }
    return reverse(dummy->next);
  }

  ListNode* reverse(ListNode* head) {
    ListNode *newHead = NULL; 
    while (head){
        ListNode * next = head->next; 
        head->next = newHead; 
        newHead = head;
        head = next;
    }
    return newHead;
  }
};





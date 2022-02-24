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
  int key;
  int val;
  LinkListNode* next;

  LinkListNode(int key, int val) {
    this->key = key;
    this->val = val;
    this->next = NULL;
  }
};

class _706_DesignHashMap {
    /**
    * 706. Design HashMap
    * Design a HashMap without using any built-in hash table libraries.

    To be specific, your design should include these functions:

    put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
    get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
    remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.

    Example:

    MyHashMap hashMap = new MyHashMap();
    hashMap.put(1, 1);          
    hashMap.put(2, 2);         
    hashMap.get(1);            // returns 1
    hashMap.get(3);            // returns -1 (not found)
    hashMap.put(2, 1);          // update the existing value
    hashMap.get(2);            // returns 1 
    hashMap.remove(2);          // remove the mapping for 2
    hashMap.get(2);            // returns -1 (not found) 

    time : O(1);
    space : O(n);
    */
 
 private:
  vector<LinkListNode*> nodes;

 public:
  /** Initialize your data structure here. */
  MyHashMap() {
    nodes.resize(10000);
  }

  /** value will always be non-negative. */
  void put(int key, int value) {
    int hashcode = hash(key);
    if (nodes[hashcode] == NULL) {
        nodes[hashcode] = new LinkListNode(-1, -1);
    }
    LinkListNode* prev = find(nodes[hashcode], key);
    if (prev->next == NULL) {
        prev->next = new LinkListNode(key, value);
    } else {
        prev->next->val = value;
    }
  }

  /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
  int get(int key) {
    int hashcode = hash(key);
    if (nodes[hashcode] == NULL) {
        return -1;
    }
    LinkListNode* prev = find(nodes[hashcode], key);
    return prev->next == NULL ? -1 : prev->next->val;
  }

  /** Removes the mapping of the specified value key if this map contains a mapping for the key */
  void remove(int key) {
    int hashcode = hash(key);
    if (nodes[hashcode] == NULL) {
        return;
    }
    LinkListNode* prev = find(nodes[hashcode], key);
    if (prev->next == NULL) {
        return;
    }
    prev->next = prev->next->next;
  }

  LinkListNode* find(LinkListNode* bucket, int key) {
    LinkListNode* node = bucket;
    LinkListNode* prev = NULL;
    
    while (node != NULL && node->key != key) {
        prev = node;
        node = node->next;
    }
    return prev;
  }

  int hash(int key) {
    return key % nodes.size();
  }
};





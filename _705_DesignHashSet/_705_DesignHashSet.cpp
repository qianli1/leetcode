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

class _705_DesignHashSet {
    /**
    * 705. Design HashSet
    * Design a HashSet without using any built-in hash table libraries.

    To be specific, your design should include these functions:

    add(value): Insert a value into the HashSet. 
    contains(value) : Return whether the value exists in the HashSet or not.
    remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.

    Example:

    MyHashSet hashSet = new MyHashSet();
    hashSet.add(1);         
    hashSet.add(2);         
    hashSet.contains(1);    // returns true
    hashSet.contains(3);    // returns false (not found)
    hashSet.add(2);          
    hashSet.contains(2);    // returns true
    hashSet.remove(2);          
    hashSet.contains(2);    // returns false (already removed)

    time : O(1);
    space : O(1);
    */
 
 private: 
  int buckets = 1000;
  int items_per_bucket = 1001;
  vector<vector<bool>> table;

 public:
  /** Initialize your data structure here. */
  MyHashSet() {
    table.resize(buckets);
  }

  int hashcode(int key) {
    return key % buckets;
  }

  int pos(int key) {
    return key / buckets;    
  }

  void add(int key) {
    int hashkey = hashcode(key);
    
    if (table[hashkey].empty()) {
        table[hashkey].resize(items_per_bucket);
    }
    table[hashkey][pos(key)] = true;
  }

  void remove(int key) {
    int hashkey = hashcode(key);
    
    if (!table[hashkey].empty()) {
        table[hashkey][pos(key)] = false;
    }
  }

  /** Returns true if this set contains the specified element */
  bool contains(int key) {
    int hashkey = hashcode(key);
    return !table[hashkey].empty() && table[hashkey][pos(key)];
  }
};





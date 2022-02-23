#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _381_InsertDeleteGetRandomO1Duplicatesallowed {
    /**
    * 381. Insert Delete GetRandom O(1) - Duplicates allowed
    * Design a data structure that supports all following operations in average O(1) time.

    Note: Duplicate elements are allowed.
    insert(val): Inserts an item val to the collection.
    remove(val): Removes an item val from the collection if present.
    getRandom: Returns a random element from current collection of elements. The probability of each element being 
    returned is linearly related to the number of same value the collection contains.
    Example:

    // Init an empty collection.
    RandomizedCollection collection = new RandomizedCollection();

    // Inserts 1 to the collection. Returns true as the collection did not contain 1.
    collection.insert(1);

    // Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
    collection.insert(1);

    // Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
    collection.insert(2);

    // getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
    collection.getRandom();

    // Removes 1 from the collection, returns true. Collection now contains [1,2].
    collection.remove(1);

    // getRandom should return 1 and 2 both equally likely.
    collection.getRandom();

    time : O(1);
    */
 
 private:
  unordered_map<int, unordered_set<int>> mp;
  vector<int> list;

 public:
  /** Initialize your data structure here. */
  RandomizedCollection() {
    
  }

  /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
  bool insert(int val) {
    list.push_back(val);
    mp[val].insert(list.size() - 1);
    return mp[val].size() == 1;
  }

  /** Removes a value from the collection. Returns true if the collection contained the specified element. */
  bool remove(int val) {
    if (mp.find(val) == mp.end()) return false;
    auto it = mp.find(val);
    auto index = *it->second.begin();
    it->second.erase(it->second.begin());
    list[index] = list.back();
    mp[list.back()].insert(index);
    mp[list.back()].erase(list.size() - 1);
    list.pop_back();
    if (it->second.size() == 0) {
        mp.erase(it);
    }
    return true;
  }

  /** Get a random element from the collection. */
  int getRandom() {
        return list[rand() % list.size()];
  }
};





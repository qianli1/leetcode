#include <queue>
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

class _379_DesignPhoneDirectory {
    /**
    * 379. Design Phone Directory
    * Design a Phone Directory which supports the following operations:

    get: Provide a number which is not assigned to anyone.
    check: Check if a number is available or not.
    release: Recycle or release a number.
    

    Example:

    // Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
    PhoneDirectory directory = new PhoneDirectory(3);

    // It can return any available phone number. Here we assume it returns 0.
    directory.get();

    // Assume it returns 1.
    directory.get();

    // The number 2 is available, so return true.
    directory.check(2);

    // It returns 2, the only number that is left.
    directory.get();

    // The number 2 is no longer available, so return false.
    directory.check(2);

    // Release number 2 back to the pool.
    directory.release(2);

    // Number 2 is available again, return true.
    directory.check(2);

    time : < O(n);
    space : O(1);
    */
 
 private:
  unordered_set<int> used;
  queue<int> q;
  int count;
    
 public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
  PhoneDirectory(int maxNumbers) {
    count = maxNumbers;
    for (int i = 0; i < count; i++) {
        q.push(i);
    }
    
  }

  /** Provide a number which is not assigned to anyone.
    @return - Return an available number. Return -1 if none is available. */
  int get() {
    if (q.empty()) {
        return -1;
    }
    int res = q.front();
    q.pop();
    used.insert(res);
    return res;
    
  }

  /** Check if a number is available or not. */
  bool check(int number) {
    if (number >= count || number < 0) {
        return false;
    }
    return !used.count(number);
  }

  /** Recycle or release a number. */
  void release(int number) {
    if (used.count(number)) {
        used.erase(number);
        q.push(number);
    }
  }
};





#include <string>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _604_DesignCompressedStringIterator {
    /**
    * 604. Design Compressed String Iterator
    * Design and implement a data structure for a compressed string iterator. It should support the following operations: next and hasNext.

    The given compressed string will be in the form of each letter followed by a positive integer representing the number of this letter 
    existing in the original uncompressed string.

    next() - if the original string still has uncompressed characters, return the next letter; Otherwise return a white space.
    hasNext() - Judge whether there is any letter needs to be uncompressed.

    Note:
    Please remember to RESET your class variables declared in StringIterator, as static/class variables are persisted across multiple test 
    cases. Please see here for more details.

    Example:

    StringIterator iterator = new StringIterator("L1e2t1C1o1d1e1");

    iterator.next(); // return 'L'
    iterator.next(); // return 'e'
    iterator.next(); // return 'e'
    iterator.next(); // return 't'
    iterator.next(); // return 'C'
    iterator.next(); // return 'o'
    iterator.next(); // return 'd'
    iterator.hasNext(); // return true
    iterator.next(); // return 'e'
    iterator.hasNext(); // return false
    iterator.next(); // return ' '

    time : O(1);
    space : O(1);
    */
 
 private: 
  string res;
  int index;

 public:
  StringIterator(string compressedString) {
    index = 0;
    int i = 0;
    while (i < compressedString.size()) {
        char ch = compressedString[i++];
        int num = 0;
        while (i < compressedString.size() && isdigit(compressedString[i])) {
            num = num * 10 + compressedString[i++] - '0';
        }
        for (int j = 0; j < num; j++) {
            res += ch;
        }
    }
  }

  char next() {
    if (!hasNext()) {
        return ' ';
    }
    return res[index++];
  }

  bool hasNext() {
    return index != res.size();
  }

 private: 
  string res2;
  int index2;
  int num;
  char ch;

 public:
  StringIterator2(string compressedString) {
    res2 = compressedString;
    index2 = 0;
    num = 0;
    ch = ' ';
  }

  char next2() {
    if (!hasNext2()) {
        return ' ';
    }
    if (num == 0) {
        ch = res2[index2++];
        while (index < res2.size() && isdigit(res2[index2])) {
            num = num * 10 + res2[index2++] - '0';
        }
    }
    num--;
    return ch;
  }

  bool hasNext2() {
    return index != res2.size() || num != 0;
  }
};





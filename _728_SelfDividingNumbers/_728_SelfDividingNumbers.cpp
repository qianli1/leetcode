#include <vector>
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

class _728_SelfDividingNumbers {
    /**
    * 728. Self Dividing Numbers
    * A self-dividing number is a number that is divisible by every digit it contains.

    For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

    Also, a self-dividing number is not allowed to contain the digit zero.

    Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.

    Example 1:
    Input: 
    left = 1, right = 22
    Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]

    time : O(n)  / O(n * log(right));
    space : O(n);
    */
 
 public:
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int> res;
    
    for (int num = left; num <= right; num++) {
        if (selfDividing(num)) {
            res.push_back(num);
        }
    }
    return res;
  }

  bool selfDividing(int num) {
    string number = to_string(num);
    for (int i = 0; i < number.size(); i++) {
        if (number[i] == '0' || num % (number[i] - '0') != 0) {
            return false;
        }
    }
    return true;
  }

  bool selfDividing2(int num) {
    int x = num;
    while (x > 0) {
        int d = x % 10;
        x /= 10;
        if (d == 0 || (num % d) != 0) {
            return false;
        }
    }
    return true;
  }
};





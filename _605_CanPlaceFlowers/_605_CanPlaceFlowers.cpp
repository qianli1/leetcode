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

class _605_CanPlaceFlowers {
    /**
    * 605. Can Place Flowers
    * Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot 
    * be planted in adjacent plots - they would compete for water and both would die.

    Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number 
    n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

    Example 1:
    Input: flowerbed = [1,0,0,0,1], n = 1
    Output: True
    Example 2:
    Input: flowerbed = [1,0,0,0,1], n = 2
    Output: False

    time : O(n);
    space : O(1);
    */
 
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int count = 0;
    int i = 0;
    while (i < flowerbed.size()) {
        if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) 
            && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
            flowerbed[i++] = 1;
            count++;
        }
        if (count >= n) {
            return true;
        }
        i++;
    }
    return false;
  }
};





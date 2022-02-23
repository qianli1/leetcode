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

class _624_MaximumDistanceinArrays {
    /**
    * 624. Maximum Distance in Arrays
    * Given m arrays, and each array is sorted in ascending order. Now you can pick up two integers from two different arrays 
    * (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their 
    * absolute difference |a-b|. Your task is to find the maximum distance.

    Example 1:
    Input: 
    [[1,2,3],
    [4,5],
    [1,2,3]]
    Output: 4
    Explanation: 
    One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
    Note:
    Each given array will have at least 1 number. There will be at least two non-empty arrays.
    The total number of the integers in all the m arrays will be in the range of [2, 10000].
    The integers in the m arrays will be in the range of [-10000, 10000].
    time : O(n);
    space : O(1);
    */
 
 public:
  int maxDistance(vector<vector<int>>& arrays) {
    int res = INT_MIN;
    int minimum = arrays[0][0];
    int maximum = arrays[0][arrays[0].size() - 1];
    
    for (int i = 1; i < arrays.size(); i++) {
        res = max(res, abs(arrays[i][0] - maximum));
        res = max(res, abs(arrays[i][arrays[i].size() - 1] - minimum));
        maximum = max(maximum, arrays[i][arrays[i].size() - 1]);
        minimum = min(minimum, arrays[i][0]);
    }
    return res;
  }  
};





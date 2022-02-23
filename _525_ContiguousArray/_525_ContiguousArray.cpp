#include <vector>
#include <unordered_map>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _525_ContiguousArray {
    /**
    * 525. Contiguous Array
    * Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

    Example 1:
    Input: [0,1]
    Output: 2
    Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
    Example 2:
    Input: [0,1,0]
    Output: 2
    Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
    Note: The length of the given binary array will not exceed 50,000.
        
    time : O(n);
    space : O(n);
    */
 
 public:
  int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> map;
    map[0] = -1;
    int res = 0;
    int count = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        count = count + (nums[i] == 1 ? 1 : - 1);
        if (map.count(count)) {
            res = max(res, i - map[count]);
        } else {
            map[count] = i;
        }
    }
    return res;
  }
};





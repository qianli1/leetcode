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

class _453_MinimumMovestoEqualArrayElements {
    /**
    * 453. Minimum Moves to Equal Array Elements
    * Given a non-empty integer array of size n, find the minimum number of moves required to 
    * make all array elements equal, where a move is incrementing n - 1 elements by 1.
    
    Example:

    Input:
    [1,2,3]

    Output:
    3

    Explanation:
    Only three moves are needed (remember each move increments two elements):

    [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

    time : O(n);
    space : O(1);
    * @param nums
    * @return
    */
 
 public:
  int minMoves(vector<int>& nums) {
    if (nums.empty() || nums.size() == 0) return 0;
    int minimum = nums[0];
    for (int num : nums) {
        minimum = min(minimum, num);
    }
    int res = 0;
    for (int num : nums) {
        res += num - minimum;
    }
    return res;
  }

  int minMoves2(vector<int>& nums) {
    if (nums.empty() || nums.size() == 0) return 0;
    int minimum = nums[0];
    long sum = 0;
    for (int num : nums) {
        sum += num;
        minimum = min(minimum, num);
    }
    return (int)(sum - minimum * nums.size());
  }
};





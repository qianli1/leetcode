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

class _719_FindKthSmallestPairDistance {
    /**
    * 719. Find K-th Smallest Pair Distance
    * Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined 
    * as the absolute difference between A and B.

    Example 1:
    Input:
    nums = [1,3,1]
    k = 1
    Output: 0 
    Explanation:
    Here are all the pairs:
    (1,3) -> 2
    (1,1) -> 0
    (3,1) -> 2
    Then the 1st smallest distance pair is (1,1), and its distance is 0.

    Time: O(nlogn)
    Space: O(1)
    */
 
 public:
  int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), low = 0, high = 1000000;
    while (low < high) {
        int mid = (low + high) / 2, cnt = 0;
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && nums[j] - nums[i] <= mid) j++;
            cnt += j - i - 1;
        }
        if (cnt < k) 
            low = mid + 1;
        else
            high = mid;
    }
    return low;
  }
};





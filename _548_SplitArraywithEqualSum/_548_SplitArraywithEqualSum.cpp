#include <vector>
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

class _548_SplitArraywithEqualSum {
    /**
    * 548. Split Array with Equal Sum
    * Given an array with n integers, you need to find if there are triplets (i, j, k) which satisfies following conditions:

    0 < i, i + 1 < j, j + 1 < k < n - 1
    Sum of subarrays (0, i - 1), (i + 1, j - 1), (j + 1, k - 1) and (k + 1, n - 1) should be equal.
    where we define that subarray (L, R) represents a slice of the original array starting from the element indexed L to the element indexed R.
    Example:
    Input: [1,2,1,2,1,2,1]
    Output: True
    Explanation:
    i = 1, j = 3, k = 5. 
    sum(0, i - 1) = sum(0, 0) = 1
    sum(i + 1, j - 1) = sum(2, 2) = 1
    sum(j + 1, k - 1) = sum(4, 4) = 1
    sum(k + 1, n - 1) = sum(6, 6) = 1

    time : O(n^2);
    space : O(n);
    */
 
 public:
  bool splitArray(vector<int>& nums) {
    if (nums.size() < 7) {
        return false;
    }
    
    vector<int> sum(nums.size());
    sum[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        sum[i] = sum[i - 1] + nums[i];
    }
    
    for (int j = 3; j < nums.size() - 3; j++) {
        unordered_set<int> s;
        for (int i = 1; i < j - 1; i++) {
            if (sum[i - 1] == sum[j - 1] - sum[i]) {
                s.insert(sum[i - 1]);
            }
        }
        for (int k = j + 2; k < nums.size() - 1; k++) {
            if (sum[nums.size() - 1] - sum[k] == sum[k - 1] - sum[j] && 
                s.count(sum[k - 1] - sum[j])) {
                return true;
            }
        }
    }
    return false;
  }
};





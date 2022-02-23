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

class _370_RangeAddition {
    /**
    * 370. Range Addition
    * Assume you have an array of length n initialized with all 0's and are given k update operations.

    Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of 
    subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.

    Return the modified array after all k operations were executed.

    Example:

    Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
    Output: [-2,0,3,5,3]
    Explanation:

    Initial state:
    [0,0,0,0,0]

    After applying operation [1,3,2]:
    [0,2,2,2,0]

    After applying operation [2,4,3]:
    [0,2,5,5,3]

    After applying operation [0,2,-2]:
    [-2,0,3,5,3]

    time : O(K + N);
    space : O(n);

    *@param length
    *@param updates
    *@return
    */
 
 public:
  vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    vector<int> res(length);
    for (vector<int> update : updates) {
        int value = update[2];
        int start = update[0];
        int end = update[1];
        res[start] += value;
        if (end + 1 < length) {
            res[end + 1] -= value;
        }
    }
    for (int i = 1; i < length; i++) {
        res[i] += res[i - 1];
    }
    return res;
  }
};





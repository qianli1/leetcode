#include <vector>
#include <string>
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

class _710_RandomPickwithBlacklist2 {
    /**
    * 710. Random Pick with Blacklist
    * Given a blacklist B containing unique integers from [0, N), write a function to return a uniform random integer from 
    * [0, N) which is NOT in B.

    Optimize it such that it minimizes the call to system’s Math.random().

    Note:

    1 <= N <= 1000000000
    0 <= B.length < min(100000, N)
    [0, N) does NOT include N. See interval notation.
    Example 1:

    Input: 
    ["Solution","pick","pick","pick"]
    [[1,[]],[],[],[]]
    Output: [null,0,0,0]
    Example 2:

    Input: 
    ["Solution","pick","pick","pick"]
    [[2,[]],[],[],[]]
    Output: [null,1,1,1]
    Example 3:

    Input: 
    ["Solution","pick","pick","pick"]
    [[3,[1]],[],[],[]]
    Output: [null,0,0,2]
    Example 4:

    Input: 
    ["Solution","pick","pick","pick"]
    [[4,[2]],[],[],[]]
    Output: [null,1,3,1]

    Time : O(n);
    Space : O(n);
    */
 
 private:
  int M;
  vector<int> black;

 public:
  Solution(int N, vector<int>& blacklist) {
    M = N - blacklist.size();
    sort(blacklist.begin(), blacklist.end());
    black = blacklist;
  }

  int pick() {
    int k = rand() % M;
    int left = 0;
    int right = black.size() - 1;
    
    while (left < right) {
        int mid = (left + right + 1) / 2;
        if (black[mid] - mid > k) {
            right = mid - 1;
        } else {
            left = mid;
        }
    }
    return left == right && black[left] - left <= k ? k + left + 1 : k;
  }
};





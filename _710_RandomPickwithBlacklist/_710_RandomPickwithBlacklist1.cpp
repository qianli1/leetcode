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

class _710_RandomPickwithBlacklist1 {
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
  unordered_map<int, int> mp;

 public:
  Solution(int N, vector<int>& blacklist) {
    M = N - blacklist.size();
    
    for (int black : blacklist) {
        mp[black] = -1;
    }
    
    for (int black : blacklist) {
        if (black < M) {
            while (mp.count(N - 1)) {
                N--;
            }
            mp[black] = N - 1;
            N--;
        }
    }
  }

  int pick() {
    int index = rand() % M;
    if (mp.count(index)) {
        return mp[index];
    }
    return index;
  }
};





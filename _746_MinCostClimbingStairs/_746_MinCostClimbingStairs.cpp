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

class _746_MinCostClimbingStairs {
    /**
    * 746. Min Cost Climbing Stairs
    * On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

    Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, 
    and you can either start from the step with index 0, or the step with index 1.

    Example 1:
    Input: cost = [10, 15, 20]
    Output: 15
    Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
    Example 2:
    Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
    Output: 6
    Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].

    time : O(n);
    space : O(1);
    */
 
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    int twoStepBefore = cost[0];
    int oneStepBefore = cost[1];
    
    for (int i = 2; i < cost.size(); i++) {
        int cur = min(twoStepBefore, oneStepBefore) + cost[i];
        twoStepBefore = oneStepBefore;
        oneStepBefore = cur;
    }
    
    return min(oneStepBefore, twoStepBefore);
  }
};





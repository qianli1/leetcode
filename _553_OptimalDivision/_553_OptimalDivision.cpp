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

class _553_OptimalDivision {
    /**
    * 553. Optimal Division
    * Given a list of positive integers, the adjacent integers will perform the float division. For example, [2,3,4] -> 2 / 3 / 4.

    However, you can add any number of parenthesis at any position to change the priority of operations. You should find out how to 
    add parenthesis to get the maximum result, and return the corresponding expression in string format. Your expression should NOT 
    contain redundant parenthesis.

    Example:
    Input: [1000,100,10,2]
    Output: "1000/(100/10/2)"
    Explanation:
    1000/(100/10/2) = 1000/((100/10)/2) = 200
    However, the bold parenthesis in "1000/((100/10)/2)" are redundant, 
    since they don't influence the operation priority. So you should return "1000/(100/10/2)". 

    Other cases:
    1000/(100/10)/2 = 50
    1000/(100/(10/2)) = 50
    1000/100/10/2 = 0.5
    1000/100/(10/2) = 2

    time : O(n);
    space : O(n);
    */
 
 public:
  string optimalDivision(vector<int>& nums) {
    if (nums.empty()) return "";
    if (nums.size() == 1) return to_string(nums[0]);
    if (nums.size() == 2) return to_string(nums[0]) + "/" + to_string(nums[1]);
    
    string res = to_string(nums[0]);
    res += "/(";
    for (int i = 1; i < nums.size() - 1; i++) {
        res += to_string(nums[i]);
        res += "/";
    }
    res += to_string(nums[nums.size() - 1]);
    res += ")";
    return res;
  }
};





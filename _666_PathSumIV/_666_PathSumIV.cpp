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

class _666_PathSumIV {
    /**
    * 666. Path Sum IV
    * If the depth of a tree is smaller than 5, then this tree can be represented by a list of three-digits integers.

    For each integer in this list:

    The hundreds digit represents the depth D of this node, 1 <= D <= 4.
    The tens digit represents the position P of this node in the level it belongs to, 1 <= P <= 8. The position is the same 
    as that in a full binary tree.
    The units digit represents the value V of this node, 0 <= V <= 9.
    Given a list of ascending three-digits integers representing a binary tree with the depth smaller than 5, you need to 
    return the sum of all paths from the root towards the leaves.

    It's guaranteed that the given list represents a valid connected binary tree.

    Example 1:

    Input: [113, 215, 221]
    Output: 12
    Explanation: 
    The tree that the list represents is:
        3
       / \
      5   1

    The path sum is (3 + 5) + (3 + 1) = 12.
    
    Example 2:

    Input: [113, 221]
    Output: 4
    Explanation: 
    The tree that the list represents is: 
        3
         \
          1

    The path sum is (3 + 1) = 4.

    Time: O(n)
    Space: O(n)
    */
 
 private:
  int res;
  unordered_map<int, int> mp;

 public:
  int pathSum(vector<int>& nums) {
    if (nums.empty() || nums.size() == 0) {
        return 0;
    }
    res = 0;
    for (int num : nums) {
        mp[num / 10] = num % 10;
    }
    helper(nums[0] / 10, 0);
    return res;
  }

  void helper(int root, int sum) {
    int level = root / 10;
    int pos = root % 10;
    int left = (level + 1) * 10 + pos * 2 - 1;
    int right = (level + 1) * 10 + pos * 2;
    
    int cur = sum + mp[root];
    if (!mp.count(left) && !mp.count(right)) {
        res += cur;
        return;
    }
    if (mp.count(left)) {
        helper(left, cur);
    }
    if (mp.count(right)) {
        helper(right, cur);
    }
  }

  int pathSum2(vector<int>& nums) {
    vector<vector<int>> tree(5, vector<int>(8));
    for(int num : nums) {
        int i = num / 100;  //i is one based index;
        int j = (num % 100) / 10 - 1;  //j used 0 based index;
        int val = num % 10;
        tree[i][j] = tree[i - 1][j / 2] + val;
    }
    int res = 0;
    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == 4 || tree[i][j] != 0 && tree[i + 1][j * 2] == 0
                && tree[i + 1][j * 2 + 1] == 0) {
                res += tree[i][j];
            }
        }
    }
    return res;
  }
};





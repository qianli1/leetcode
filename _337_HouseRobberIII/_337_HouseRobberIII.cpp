#include <vector>
#include <cmath>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class _337_HouseRobberIII {
    /**
    * 337. House Robber III
    * The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

    Determine the maximum amount of money the thief can rob tonight without alerting the police.

    Example 1:

    Input: [3,2,3,null,3,null,1]

         3
        / \
       2   3
        \   \ 
         3   1

    Output: 7 
    Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

    Example 2:

    Input: [3,4,5,1,3,null,1]

         3
        / \
       4   5
      / \   \ 
     1   3   1

    Output: 9
    Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

    time : O(n);
    space : O(h);
    * @param root
    * @return
    */
 
 public:
  int rob(TreeNode* root) {
    if (!root) return 0;
    int val = 0;
    if (root->left) {
        val += rob(root->left->left) + rob(root->left->right);
    }
    if (!root->right) {
        val += rob(root->right->left) + rob(root->right->right);
    }
    return max(val + root->val, rob(root->left) + rob(root->right));
  }

  int rob2(TreeNode* root) {
    vector<int> res = robSub(root);
    return max(res[0], res[1]);
  }

  vector<int> robSub(TreeNode* root) {
    if (!root) return {0, 0};
    vector<int> left = robSub(root->left);
    vector<int> right = robSub(root->right);
    vector<int> res(2); 
    res[0] = max(left[0], left[1]) + max(right[0], right[1]);
    res[1] = root->val + left[0] + right[0];
    return res;
  }
};





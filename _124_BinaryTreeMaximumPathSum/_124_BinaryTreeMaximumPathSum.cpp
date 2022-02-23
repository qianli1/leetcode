#include <climits>
#include <algorithm> 
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


class _124_BinaryTreeMaximumPathSum {
    /**
    * 124. Binary Tree Maximum Path Sum
    * Given a non-empty binary tree, find the maximum path sum.

    For this problem, a path is defined as any sequence of nodes from some starting node to any node 
    in the tree along the parent-child connections. The path must contain at least one node and does not 
    need to go through the root.

    For example:
    Given the below binary tree,

        1
       / \
      2   3
      Return 6.

          3
         / \
        9   20
       / \ 
      15  7
      Return 47.

    */
 private:
  int res_;

 public:
  int maxPathSum(TreeNode* root) {
    if (!root) return 0;
    res_ = INT_MIN;
    helper(root);
    return res_;
  }

  int helper(TreeNode* root) {
    if (!root) return 0;
    int left = max(0, helper(root->left));
    int right = max(0, helper(root->right));
    res_ = max(res_, left + right + root->val);
    return max(left, right) + root->val;  
  }
};

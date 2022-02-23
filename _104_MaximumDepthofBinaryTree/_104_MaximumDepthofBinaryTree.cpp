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


class _104_MaximumDepthofBinaryTree {
    /**
    * 104. Maximum Depth of Binary Tree
    * Given a binary tree, find its maximum depth.

    The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
    *
    * @param root
    * @return
    */
 public:
  int maxDepth(TreeNode* root) {
    if (!root) return 0;
    int left = maxDepth(root->left) + 1;
    int right = maxDepth(root->right) + 1;
    return max(left, right);
  }
};

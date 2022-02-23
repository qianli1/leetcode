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

class _549_BinaryTreeLongestConsecutiveSequenceII {
    /**
    * 536. Construct Binary Tree from String
    * Given a binary tree, you need to find the length of Longest Consecutive Path in Binary Tree.

    Especially, this path can be either increasing or decreasing. For example, [1,2,3,4] and [4,3,2,1] are both considered 
    valid, but the path [1,2,4,3] is not valid. On the other hand, the path can be in the child-Parent-child order, where 
    not necessarily be parent-child order.

    Example 1:

    Input:
         1
        / \
       2   3
    Output: 2
    Explanation: The longest consecutive path is [1, 2] or [2, 1].
    

    Example 2:

    Input:
         2
        / \
       1   3
    Output: 3
    Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].

    time : O(n);
    space : O(n);
    */

 private:
  int res;

 public:
  int longestConsecutive(TreeNode* root) {
    res = 0;
    helper(root);
    return res;
  }

  vector<int> helper(TreeNode* root) {
    if (root == NULL) {
        return {0, 0};
    }
    vector<int> left = helper(root->left);
    vector<int> right = helper(root->right);
    int dcr = 1;
    int icr = 1;
    
    if (root->left != NULL) {
        if (root->left->val == root->val + 1) {
            icr = left[1] + 1;
        }
        if (root->left->val == root->val - 1) {
            dcr = left[0] + 1;
        }
    }
    if (root->right != NULL) {
        if (root->right->val == root->val + 1) {
            icr = max(icr, right[1] + 1);
        }
        if (root->right->val == root->val - 1) {
            dcr = max(dcr, right[0] + 1);
        }
    }
    res = max(res, dcr + icr - 1);
    return {dcr, icr};
  }
};





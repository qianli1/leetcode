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


class _230_KthSmallestElementinaBST {
    /**
    * 230. Kth Smallest Element in a BST
    * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
    *
    * @param root
    * @param K
    * @return
    */
 private:
  int count_;
  int res_;

 public:
  int kthSmallest(TreeNode* root, int k) {
    count_ = k;
    res_ = 0;
    helper(root);
    return res_;
  }

  void helper(TreeNode* root) {
      if (!root) return;
      helper(root->left);
      count_--;
      if (count_ == 0) {
          res_ = root->val;
      }
      helper(root->right);
  }
};

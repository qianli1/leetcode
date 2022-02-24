#include <vector>
#include <unordered_set>

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

class _653_TwoSumIVInputisaBST {
    /**
    * 653. Two Sum IV - Input is a BST
    * Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum 
    * is equal to the given target.

    Example 1:

    Input: 
         5
        / \
       3   6
      / \   \
     2   4   7

    Target = 9

    Output: True
    

    Example 2:

    Input: 
        5
       / \
      3   6
     / \   \
    2   4   7

    Target = 28

    Output: False
    */
 
 public:
  //Time: O(n), Space: O(n)
  bool findTarget(TreeNode* root, int k) {
    if (root == NULL) return false;
    unordered_set<int> s;
    return helper(root, k, s);
  }

  bool helper(TreeNode* root, int k, unordered_set<int>& s) {
    if (root == NULL) return false;
    if (s.count(k - root->val)) {
        return true;
    }
    s.insert(root->val);
    return helper(root->left, k, s) || helper(root->right, k, s);
  }

  //Time: O(nlogn), Space: O(h), h : logn ~ n
  bool findTarget2(TreeNode* root, int k) {
    return firstDfs(root, root, k);
  }

  bool firstDfs(TreeNode* first, TreeNode* second, int k) {
    if (first == NULL) return false;
    return secondDfs(first, second, k - first->val) 
        || firstDfs(first->left, second, k) 
        || firstDfs(first->right, second, k);
  }

  bool secondDfs(TreeNode* first, TreeNode* second, int k) {
    if (second == NULL) return false;
    return (second->val == k) && (first != second)
        || (second->val > k) && secondDfs(first, second->left, k) 
        || (second->val < k) && secondDfs(first, second->right, k);
  }
};





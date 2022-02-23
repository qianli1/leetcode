#include <vector>

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

class _617_MergeTwoBinaryTrees {
    /**
    * 617. Merge Two Binary Trees
    * Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are 
    * overlapped while the others are not.

    You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as 
    the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

    Example 1:

    Input: 
        Tree 1                     Tree 2                  
             1                         2                             
            / \                       / \                            
           3   2                     1   3                        
          /                           \   \                      
         5                             4   7                  
    Output: 
    Merged tree:
             3
            / \
           4   5
          / \   \ 
         5   4   7

    time : O(n);
    space : O(n);
    */
 
 public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL) return t2;
        if (t2 == NULL) return t1;
        TreeNode* new_node = new TreeNode(t1->val + t2->val);
        new_node->left = mergeTrees(t1->left, t2->left);
        new_node->right = mergeTrees(t1->right, t2->right);
        return new_node;
    }
};





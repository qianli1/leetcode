#include <vector>
#include <queue>

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

class _623_AddOneRowtoTree {
    /**
    * 623. Add One Row to Tree
    * Given the root of a binary tree, then value v and depth d, you need to add a row of nodes with value v at the given 
    * depth d. The root node is at depth 1.

    The adding rule is: given a positive integer depth d, for each NOT null tree nodes N in depth d-1, create two tree nodes 
    with value v as N's left subtree root and right subtree root. And N's original left subtree should be the left subtree of 
    the new left subtree root, its original right subtree should be the right subtree of the new right subtree root. If depth 
    d is 1 that means there is no depth d-1 at all, then create a tree node with value v as the new root of the whole original 
    tree, and the original tree is the new root's left subtree.

    Example 1:
    Input: 
    A binary tree as following:
          4
        /   \
       2     6
      / \   / 
     3   1 5   

    v = 1

    d = 2

    Output: 
          4
         / \
        1   1
       /     \
      2       6
     / \     / 
    3   1   5   

    Example 2:
    Input: 
    A binary tree as following:
         4
        /   
       2    
     / \   
    3   1    

    v = 1

    d = 3

    Output: 
          4
         /   
        2
       / \    
      1   1
     /     \  
    3       1

    time : O(n);
    space : O(h);
    */
 
 public:
  TreeNode* addOneRow(TreeNode* root, int v, int d) {
    if (d == 1) {
        TreeNode* new_root = new TreeNode(v);
        new_root->left = root;
        return new_root;
    }
    queue<TreeNode*> q;
    q.push(root);
    for (int i = 1; i < d - 1; i++) {
        int size = q.size();
        for (int j = 0; j < size; j++) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left != NULL) {
                q.push(node->left);
            }
            if (node->right != NULL) {
                q.push(node->right);
            }
        }
    }
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        TreeNode* tmp = node->left;
        node->left = new TreeNode(v);
        node->left->left = tmp;
        tmp = node->right;
        node->right = new TreeNode(v);
        node->right->right = tmp;
    }
    return root;
  }

  TreeNode* addOneRow2(TreeNode* root, int v, int d) {
    if (d < 2) {
        TreeNode* new_root = new TreeNode(v);
        if (d == 0) {
            new_root->right = root;
        } else {
            new_root->left = root;
        }
        return new_root;
    }
    if (root == NULL) return NULL;
    root->left = addOneRow2(root->left, v, d == 2 ? 1 : d - 1);
    root->right = addOneRow2(root->right, v, d == 2 ? 0 : d - 1);
    
    return root;
  }
};





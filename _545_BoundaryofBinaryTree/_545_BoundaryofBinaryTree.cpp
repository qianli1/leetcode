#include <vector>
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


class _545_BoundaryofBinaryTree {
    /**
    * 545. Boundary of Binary Tree
    * Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root. Boundary 
    * includes left boundary, leaves, and right boundary in order without duplicate nodes.  (The values of the nodes 
    * may still be duplicates.)

    Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the path from root 
    to the right-most node. If the root doesn't have left subtree or right subtree, then the root itself is left boundary 
    or right boundary. Note this definition only applies to the input binary tree, and not applies to any subtrees.

    The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if exists. 
    If not, travel to the right subtree. Repeat until you reach a leaf node.

    The right-most node is also defined by the same way with left and right exchanged.

    Example 1

    Input:
     1
      \
        2
       / \
      3   4

    Ouput:
    [1, 3, 4, 2]

    Explanation:
    The root doesn't have left subtree, so the root itself is left boundary.
    The leaves are node 3 and 4.
    The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
    So order them in anti-clockwise without duplicates and we have [1,3,4,2].
    

    Example 2

        Input:
         ____1_____
        /          \
       2            3
      / \          / 
     4   5        6   
        / \      / \
       7   8    9  10  
        
    Ouput:
    [1,2,4,7,8,9,10,6,3]

    Explanation:
    The left boundary are node 1,2,4. (4 is the left-most node according to definition)
    The leaves are node 4,7,8,9,10.
    The right boundary are node 1,3,6,10. (10 is the right-most node).
    So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].

    Time : O(n);
    Space : O(h);

    */
 private:
  vector<int> res;

 public:
  vector<int> boundaryOfBinaryTree(TreeNode* root) {
    if (root == NULL) {
        return res;
    }
    res.push_back(root->val);
    leftBoundary(root->left);
    leaves(root->left);
    leaves(root->right);
    rightBoundary(root->right);
    return res;
  }

  void leftBoundary(TreeNode* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return;
    }
    res.push_back(root->val);
    if (root->left == NULL) {
        leftBoundary(root->right);
    } else {
        leftBoundary(root->left);
    }
  }

  void rightBoundary(TreeNode* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return;
    }
    if (root->right == NULL) {
        rightBoundary(root->left);
    } else {
        rightBoundary(root->right);
    }
    res.push_back(root->val);
  }

  void leaves(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        res.push_back(root->val);
        return;
    }
    leaves(root->left);
    leaves(root->right);
  }
};

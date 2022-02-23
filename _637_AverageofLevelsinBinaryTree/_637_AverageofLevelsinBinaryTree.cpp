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

class _637_AverageofLevelsinBinaryTree {
    /**
    * 637. Average of Levels in Binary Tree
    * Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
    Example 1:
    Input:
      3
     / \
    9  20
      /  \
     15   7
    Output: [3, 14.5, 11]
    Explanation:
    The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].

    time : O(n);
    space : O(n);
    */
 
 public:
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> res;
    if (root == NULL) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        double sum = 0;
        for (int i = 0; i < size; i++) {
            TreeNode* cur = q.front();
            q.pop();
            sum += cur->val;
            if (cur->left != NULL) q.push(cur->left);
            if (cur->right != NULL) q.push(cur->right);
        }
        res.push_back(sum / size);
    }
    return res;
  }
};





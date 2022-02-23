#include <vector>
#include <string>

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

class _606_ConstructStringfromBinaryTree {
    /**
    * 606. Construct String from Binary Tree
    * You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.

    The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs 
    that don't affect the one-to-one mapping relationship between the string and the original binary tree.

    Example 1:
    Input: Binary tree: [1,2,3,4]
          1
        /   \
       2     3
     /    
    4     

    Output: "1(2(4))(3)"

    Explanation: Originallay it needs to be "1(2(4)())(3()())", 
    but you need to omit all the unnecessary empty parenthesis pairs. 
    And it will be "1(2(4))(3)".
    Example 2:
    Input: Binary tree: [1,2,3,null,4]
          1
        /   \
       2     3
        \  
         4 

    Output: "1(2()(4))(3)"

    Explanation: Almost the same as the first example, 
    except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.

    time : O(n);
    space : O(h);
    */
 
 public:
  string tree2str(TreeNode* t) {
    if (t == NULL) {
        return "";
    }
    if (t->left == NULL && t->right == NULL) {
        return to_string(t->val) + "";
    }
    if (t->right == NULL) {
        return to_string(t->val) + "(" + tree2str(t->left) + ")";
    }
    return to_string(t->val) + "(" + tree2str(t->left) + ")(" + tree2str(t->right) + ")";
    
  }
};





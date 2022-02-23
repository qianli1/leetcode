#include <vector>
#include <string>
#include <stack>

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

class _536_ConstructBinaryTreefromString {
    /**
    * 536. Construct Binary Tree from String
    * You need to construct a binary tree from a string consisting of parenthesis and integers.

    The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. 
    The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

    You always start to construct the left child node of the parent first if it exists.

    Example:
    Input: "4(2(3)(1))(6(5))"
    Output: return the tree root node representing the following tree:

          4
        /   \
       2     6
      / \   / 
     3   1 5   
    Note:
    There will only be '(', ')', '-' and '0' ~ '9' in the input string.
    An empty tree is represented by "" instead of "()".

    time : O(n);
    space : O(n);
    */

public:
  TreeNode* str2tree(string s) {
    if (s.empty() || s.size() == 0) {
        return NULL;
    }
    stack<TreeNode*> st;
    for (int i = 0; i < s.size(); i++) {
        int j = i;
        char c = s[i];
        if (c == ')') {
            st.pop();
        } else if (isdigit(c) || c == '-') {
            while (i + 1 < s.size() && s[i + 1] >= '0' && s[i + 1] <= '9') {
                i++;
            }
            TreeNode* cur = new TreeNode(stoi(s.substr(j, i + 1 - j)));
            if (!st.empty()) {
                TreeNode* parent = st.top();
                if (parent->left != NULL) {
                    parent->right = cur;
                } else {
                    parent->left = cur;
                }
            }
            st.push(cur);
        }
    }
    return st.top();   
  }
};





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

class _547_FriendCircles {
    /**
    * 547. Friend Circles
    * There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive 
    * in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend 
    * of C. And we defined a friend circle is a group of students who are direct or indirect friends.

    Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith 
    and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend 
    circles among all the students.

    Example 1:
    Input: 
    [[1,1,0],
    [1,1,0],
    [0,0,1]]
    Output: 2
    Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
    The 2nd student himself is in a friend circle. So return 2.
    Example 2:
    Input: 
    [[1,1,0],
    [1,1,1],
    [0,1,1]]
    Output: 1
    Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
    so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.

    time : O(edges * nodes);
    space : O(n);
    */
 
 public:
  int findCircleNum(vector<vector<int>>& M) {
    vector<int> visited(M.size());
    int res = 0;
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] == 0) {
            dfs(M, visited, i);
            res++;
        }
    }
    return res;
  }

  void dfs(vector<vector<int>>& M, vector<int>& visited, int i) {
    for (int j = 0; j < visited.size(); j++) {
        if (M[i][j] == 1 && visited[j] == 0) {
            visited[j] = 1;
            dfs(M, visited, j);
        } 
    }
  }

  int findCircleNum2(vector<vector<int>>& M) {
    int res = M.size();
    
    vector<int> roots(M.size(), -1);
    
    for (int i = 0; i < M.size(); i++) {
        for (int j = 0; j < M[0].size(); j++) {
            if (M[i][j] == 1) {
                int x = find(roots, i);
                int y = find(roots, j);
                if (x != y) {
                    roots[x] = y;
                    res--;
                }
            }
        }
    }
    return res;
  }

  int find(vector<int>& roots, int i) {
    while (roots[i] != -1) {
        i = roots[i];
    }
    return i;
  }
};





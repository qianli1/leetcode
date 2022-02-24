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

class _684_RedundantConnection {
    /**
    * 684. Redundant Connection
    * In this problem, a tree is an undirected graph that is connected and has no cycles.

    The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge 
    added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

    The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an 
    undirected edge connecting nodes u and v.

    Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return 
    the answer that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.

    Example 1:
    Input: [[1,2], [1,3], [2,3]]
    Output: [2,3]
    Explanation: The given undirected graph will be like this:
      1
     / \
    2 - 3
    Example 2:
    Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
    Output: [1,4]
    Explanation: The given undirected graph will be like this:
    5 - 1 - 2
        |   |
        4 - 3

    Time: O(n)约等于
    Space: O(n)
    */
 
 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    vector<int> roots(edges.size() + 1);
    
    for (auto edge : edges) {
        int u = find(roots, edge[0]);
        int v = find(roots, edge[1]);
        if (u == v) {
            return edge;
        }
        roots[u] = v;
    }
    vector<int> res;
    return res;
  }

  int find(vector<int>& roots, int v) {
    return roots[v] == 0 ? v : find(roots, roots[v]);
  }
};





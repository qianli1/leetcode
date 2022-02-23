#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

struct GraphNode{
    string den;
    double val;
    GraphNode(string den, double val) {
        this->den = den;
        this->val = val;
    }
};

class _399_EvaluateDivision {
    /**
    * 399. Evaluate Division
    * Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real 
    * number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

    Example:
    Given a / b = 2.0, b / c = 3.0.
    queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
    return [6.0, 0.5, -1.0, 1.0, -1.0 ].

    The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , 
    where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

    According to the example above:

    equations = [ ["a", "b"], ["b", "c"] ],
    values = [2.0, 3.0],
    queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
    

    The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.

    time : O(V+E);
    space : O(n);
    */
 
 private:
  unordered_map<string, vector<GraphNode>> mp;

 public:
  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    for (int i = 0; i < equations.size(); i++) {
        vector<string> equation = equations[i];
        mp[equation[0]].push_back(GraphNode(equation[1], values[i]));
        mp[equation[1]].push_back(GraphNode(equation[0], 1 / values[i]));
    }
    vector<double> res(queries.size());
    for (int i = 0; i < res.size(); i++) {
        unordered_set<string> visited;
        res[i] = find(queries[i][0], queries[i][1], 1, visited);
    }
    return res;
  }

  double find(string start, string end, double value, unordered_set<string>& visited) {
    if (visited.count(start)) return -1;
    if (!mp.count(start)) return -1;
    if (start == end) return value;
    visited.insert(start);
    for (GraphNode next : mp[start]) {
        double sub = find(next.den, end, value * next.val, visited);
        if (sub != -1.0) return sub;
    }
    visited.erase(start);
    return -1;
  }
};





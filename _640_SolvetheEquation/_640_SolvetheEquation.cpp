#include <vector>
#include <string>
#include <regex>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _640_SolvetheEquation {
    /**
    * 640. Solve the Equation
    * Solve a given equation and return the value of x in the form of string "x=#value". The equation contains only '+', '-' 
    * operation, the variable x and its coefficient.

    If there is no solution for the equation, return "No solution".

    If there are infinite solutions for the equation, return "Infinite solutions".

    If there is exactly one solution for the equation, we ensure that the value of x is an integer.

    Example 1:
    Input: "x+5-3+x=6+x-2"
    Output: "x=2"
    Example 2:
    Input: "x=x"
    Output: "Infinite solutions"
    Example 3:
    Input: "2x=x"
    Output: "x=0"
    Example 4:
    Input: "2x+3x-6x=x+2"
    Output: "x=-1"
    Example 5:
    Input: "x=x+2"
    Output: "No solution"
    */
 
 public:
  string solveEquation(string equation) {
    equation = regex_replace(equation, regex("(^|[+=-])x"), "$011x");

    // calculate coefficients for both sides
    auto pos = equation.find('=');
    vector<int> left_part = evaluate(equation.substr(0, pos));
    vector<int> right_part = evaluate(equation.substr(pos + 1));

    // l.first x + l.second = r.first x + r.second => ax = b
    int count_x = left_part[0] - right_part[0];
    int count_num = right_part[1] - left_part[1];

    return count_x != 0 ? "x=" + to_string(count_num/count_x) : count_num != 0 ? "No solution" : "Infinite solutions";
  }

  vector<int> evaluate(string s) {
    // split the side into form of (+/-)123x
    auto e = regex("(^|[+-])\\d+x?");
    regex_token_iterator<string::iterator> it(s.begin(), s.end(), e), end;

    int a = 0, b = 0;
    for (; it != end; it++)
        (it->str().back() == 'x' ? a : b) += stoi(*it);

    return {a, b};
  }
};





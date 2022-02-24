#include <vector>
#include <string> 
#include <unordered_map>
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

class _726_NumberofAtoms {
    /**
    * 726. Number of Atoms
    * Given a chemical formula (given as a string), return the count of each atom.

    An atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

    1 or more digits representing the count of that element may follow if the count is greater than 1. If the count is 1, no 
    digits will follow. For example, H2O and H2O2 are possible, but H1O2 is impossible.

    Two formulas concatenated together produce another formula. For example, H2O2He3Mg4 is also a formula.

    A formula placed in parentheses, and a count (optionally added) is also a formula. For example, (H2O2) and (H2O2)3 are 
    formulas.

    Given a formula, output the count of all elements as a string in the following form: the first name (in sorted order), 
    followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its 
    count (if that count is more than 1), and so on.

    Example 1:
    Input: 
    formula = "H2O"
    Output: "H2O"
    Explanation: 
    The count of elements are {'H': 2, 'O': 1}.
    Example 2:
    Input: 
    formula = "Mg(OH)2"
    Output: "H2MgO2"
    Explanation: 
    The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
    Example 3:
    Input: 
    formula = "K4(ON(SO3)2)2"
    Output: "K4N2O14S4"
    Explanation: 
    The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.

    Time: O(n^2)
    Space: O(n)
    */
 
 public:
  string countOfAtoms(string formula) {
    stack<unordered_map<string, int>> st;
    unordered_map<string, int> mp;
    int index = 0;
    int n = formula.size();
    
    while (index < n) {
        char c = formula[index];
        index++;
        if (c == '(') {
            st.push(mp);
            mp.clear();
        } else if (c == ')') {
            int num = 0;
            while (index < n && isdigit(formula[index])) {
                num = num * 10 + formula[index++] - '0';
            }
            if (!st.empty()) {
                unordered_map<string, int> temp = mp;
                mp = st.top();
                st.pop();
                for (auto& v : temp) {
                    mp[v.first] += v.second * (num == 0 ? 1 : num);
                }
            }
        } else {
            int start = index - 1;
            while (index < n && islower(formula[index])) {
                index++;
            } 
            string s = formula.substr(start, index - start);
            int num = 0;
            while (index < n && isdigit(formula[index])) {
                num = num * 10 + formula[index++] - '0';
            }
            mp[s] += (num == 0 ? 1 : num);
        }
    }
    string sb;
    vector<string> list;
    for (auto& v : mp) {
        list.push_back(v.first);
    }
    sort(list.begin(), list.end());
    for (string s : list) {
        sb += s;
        if (mp[s] > 1) {
            sb += to_string(mp[s]);
        }
    }
    return sb;
  }
};





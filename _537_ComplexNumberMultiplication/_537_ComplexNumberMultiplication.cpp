#include <string>
#include <sstream>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _537_ComplexNumberMultiplication {
    /**
    * 537. Complex Number Multiplication
    * Given two strings representing two complex numbers.

    You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

    Example 1:
    Input: "1+1i", "1+1i"
    Output: "0+2i"
    Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
    Example 2:
    Input: "1+-1i", "1+-1i"
    Output: "0+-2i"
    Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
    Note:

    The input strings will not have extra blank.
    The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range 
    of [-100, 100]. And the output should be also in this form.

    time : O(1);
    space : O(1);
    */
 
 public:
  string complexNumberMultiply(string a, string b) {
    int a_real, a_img, b_real, b_img;
    char buff;
    stringstream aa(a), bb(b), res;
    aa >> a_real >> buff >> a_img >> buff;
    bb >> b_real >> buff >> b_img >> buff;
    res << a_real * b_real - a_img * b_img << "+" << a_real * b_img + b_real * a_img << "i";
    return res.str();
  }
};





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

class _443_StringCompression {
    /**
    * 443. String Compression
    * Given an array of characters, compress it in-place.

    The length after compression must always be smaller than or equal to the original array.

    Every element of the array should be a character (not int) of length 1.

    After you are done modifying the input array in-place, return the new length of the array.

 
    Follow up:
    Could you solve it using only O(1) extra space?

    Example 1:
    Input:
    ["a","a","b","b","c","c","c"]

    Output:
    Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

    Explanation:
    "aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".
    Example 2:
    Input:
    ["a"]

    Output:
    Return 1, and the first 1 character of the input array should be: ["a"]

    Explanation:
    Nothing is replaced.
    Example 3:
    Input:
    ["a","b","b","b","b","b","b","b","b","b","b","b","b"]

    Output:
    Return 4, and the first 4 characters of the input array should be ["a", "b", "1", "2"].

    Explanation:
    Since the character "a" does not repeat, it is not compressed."bbbbbbbbbbb" is replaced by "b12".
    Notice each digit has its own entry in the array.

    time : O(n);
    space : O(1);
    * @param chars
    * @return
    */
 public:
  int compress(vector<char>& chars) {
    int res = 0, index = 0;
    while (index < chars.size()) {
        char cur = chars[index];
        int count = 0;
        while (index < chars.size() && chars[index] == cur) {
            index++;
            count++;
        }
        chars[res++] = cur;
        if (count != 1) {
            for (char c : to_string(count)) {
                chars[res++] = c;
            }
        }
    }
    return res;
  }
};

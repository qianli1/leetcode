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

class _744_FindSmallestLetterGreaterThanTarget {
    /**
    * 744. Find Smallest Letter Greater Than Target
    * Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, find the 
    * smallest element in the list that is larger than the given target.

    Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.

    Examples:
    Input:
    letters = ["c", "f", "j"]
    target = "a"
    Output: "c"

    Input:
    letters = ["c", "f", "j"]
    target = "c"
    Output: "f"

    Input:
    letters = ["c", "f", "j"]
    target = "d"
    Output: "f"

    Input:
    letters = ["c", "f", "j"]
    target = "g"
    Output: "j"

    Input:
    letters = ["c", "f", "j"]
    target = "j"
    Output: "c"

    Input:
    letters = ["c", "f", "j"]
    target = "k"
    Output: "c"

    time : O(logn);
    space : O(1);
    */
 
 public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    for (char c : letters) {
        if (c > target) {
            return c;
        }
    }
    return letters[0];
  }

  char nextGreatestLetter2(vector<char>& letters, char target) {
    int left = 0;
    int right = letters.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (target >= letters[mid]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return letters[left] > target ? letters[left] : letters[0]; 
  }
};





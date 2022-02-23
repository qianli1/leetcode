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

class _418_SentenceScreenFitting {
    /**
    * 418. Sentence Screen Fitting
    * Given a rows x cols screen and a sentence represented by a list of non-empty words, find how many times the 
    * given sentence can be fitted on the screen.

    Note:

    A word cannot be split into two lines.
    The order of words in the sentence must remain unchanged.
    Two consecutive words in a line must be separated by a single space.
    Total words in the sentence won't exceed 100.
    Length of each word is greater than 0 and won't exceed 10.
    1 ≤ rows, cols ≤ 20,000.
    Example 1:

    Input:
    rows = 2, cols = 8, sentence = ["hello", "world"]

    Output: 
    1

    Explanation:
    hello---
    world---

    The character '-' signifies an empty space on the screen.
    Example 2:

    Input:
    rows = 3, cols = 6, sentence = ["a", "bcd", "e"]

    Output: 
    2

    Explanation:
    a-bcd- 
    e-a---
    bcd-e-

    The character '-' signifies an empty space on the screen.
    Example 3:

    Input:
    rows = 4, cols = 5, sentence = ["I", "had", "apple", "pie"]

    Output: 
    1

    Explanation:
    I-had
    apple
    pie-I
    had--

    The character '-' signifies an empty space on the screen.

    time : O(n);
    space : O(1);
    */
 
 public:
  int wordsTyping(vector<string>& sentence, int rows, int cols) {
    string s;
    s.clear();
    for (string word : sentence) {
        s += word;
        s += " ";
    }
    int start = 0;
    int len = s.size();
    for (int i = 0; i < rows; i++) {
        start += cols;
        if (s[start % len] == ' ') {
            start++;
        } else {
            while (start > 0 && s[(start - 1) % len] != ' ') {
                start--;
            }
        }
    }
    return start / len;
  }
};





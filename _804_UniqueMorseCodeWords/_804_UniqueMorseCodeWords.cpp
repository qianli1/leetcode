#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _804_UniqueMorseCodeWords {
    /**
    * 804. Unique Morse Code Words
    * International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows: 
    * "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.

    For convenience, the full table for the 26 letters of the English alphabet is given below:

    [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-",
    "...-",".--","-..-","-.--","--.."]
    Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter. For example, "cab" can 
    be written as "-.-..--...", (which is the concatenation "-.-." + ".-" + "-..."). We'll call such a concatenation, the transformation 
    of a word.

    Return the number of different transformations among all words we have.

    Example:
    Input: words = ["gin", "zen", "gig", "msg"]
    Output: 2
    Explanation: 
    The transformation of each word is:
    "gin" -> "--...-."
    "zen" -> "--...-."
    "gig" -> "--...--."
    "msg" -> "--...--."

    There are 2 different transformations, "--...-." and "--...--.".

    time : O(n * len) / O(S);
    space : O(n * len) / O(S);
    */
 
 public:
  int uniqueMorseRepresentations(vector<string>& words) {
    vector<string> dict = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",
    ".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    unordered_set<string> s;
    for (string word : words) {
        string sb;
        for (int i = 0; i < word.size(); i++) {
            sb += dict[word[i] - 'a'];
        }
        s.insert(sb);
    }
    return s.size();
  }
};





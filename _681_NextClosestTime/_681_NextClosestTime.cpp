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

class _681_NextClosestTime {
    /**
    * 681. Next Closest Time
    * Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no 
    * limit on how many times a digit can be reused.

    You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are 
    all invalid.

    Example 1:

    Input: "19:34"
    Output: "19:39"
    Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, 
    because this occurs 23 hours and 59 minutes later.
    Example 2:

    Input: "23:59"
    Output: "22:22"
    Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is 
    next day's time since it is smaller than the input time numerically.

    Time: O(1)
    Space: O(1)
    */
 
 public:
  string nextClosestTime(string time) {
    string res = time;
    vector<char> digits;
    digits.push_back(res[0]);
    digits.push_back(res[1]);
    digits.push_back(res[3]);
    digits.push_back(res[4]);
    sort(digits.begin(), digits.end());
    
    //HH:M_ 无上界， 23：43 -> 23: 44
    res[4] = findNext(res[4], (char)('9' + 1), digits);
    if (res[4] > time[4]) {
        return res;
    }
    
    //HH:_M 分钟5上界  14:29 -> 14:21 -> 14: 41
    res[3] = findNext(res[3], '5', digits);
    if (res[3] > time[3]) {
        return res;
    }
    
    //H_:MM 小时：20-23 10-19  02:37 -> 03:00 
    res[1] = res[0] == '2' ? findNext(res[1], '3', digits) : findNext(res[1], (char)('9' + 1), digits);
    if (res[1] > time[1]) {
        return res;
    }
    
    //_H:MM 小时 0-2， 19:59 -> 11:11
    res[0] = findNext(res[0], '2', digits);
    return res;
  }

  char findNext(char cur, char upperLimit, vector<char>& digits){
    if (cur == upperLimit) {
        return digits[0];
    }
    int pos = binarySearch(digits, cur) + 1;
    while (pos < 4 && (digits[pos] > upperLimit || digits[pos] == cur)) {  //如果大于最大值，直接到最后的位置，最后return digits[0]
            pos++;
    }
    return pos == 4 ? digits[0] : digits[pos];
  }

  int binarySearch(vector<char>& digits, char cur) {
    int l = 0, r = digits.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (digits[mid] > cur) {
            r = mid - 1;
        } else if (digits[mid] < cur) {
            l = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
  }
};





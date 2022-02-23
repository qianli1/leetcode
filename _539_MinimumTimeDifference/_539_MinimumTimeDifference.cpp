#include <string>
#include <vector>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

struct Time {
    int hour;
    int minute;
    Time(int _hour, int _minute) : hour(_hour), minute(_minute) {}
    
    friend bool operator < (const Time& one, const Time& other) {
        if (one.hour == other.hour) {
            return one.minute < other.minute;
        }
        return one.hour < other.hour;
    }
    
    int getDiff(Time other) {
        return (this->hour - other.hour) * 60 + (this->minute - other.minute);
    }
};

class _539_MinimumTimeDifference {
    /**
    * 539. Minimum Time Difference
    * Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.
    Example 1:
    Input: ["23:59","00:00"]
    Output: 1
    Note:
    The number of time points in the given list is at least 2 and won't exceed 20000.
    The input time is legal and ranges from 00:00 to 23:59.

    time : O(24 * 60);
    space : O(24 * 60);
    */
 
 public:
  int findMinDifference(vector<string>& timePoints) {
    vector<bool> mark(24 * 60, false);
    for (string& time : timePoints) {
        int hour = stoi(time.substr(0, 2));
        int minute = stoi(time.substr(3, 2));
        if (mark[hour * 60 + minute]) {
            return 0;
        }
        mark[hour * 60 + minute] = true;
    }
    int res = INT_MAX;
    int pre = -1;
    int first = -1;
    for (int i = 0; i < mark.size(); i++) {
        if (mark[i]) {
            if (first == -1) {
                first = i;
            } else {
                res = min(res, i - pre);
            }
            pre = i;
        }
    }
    res = min(res, (first + 24 * 60 - pre));
    return res;
  }


  int findMinDifference2(vector<string>& timePoints) {
    vector<Time> times;
    for (string& time : timePoints) {
        times.push_back(Time(stoi(time.substr(0, 2)), stoi(time.substr(3, 2))));
    }
    sort(times.begin(), times.end());
    Time first = times[0];
    times.push_back(Time(first.hour + 24, first.minute));
    int min_diff = INT_MAX;
    for (int i = 0; i < timePoints.size(); i++) {
        int diff = abs(times[i].getDiff(times[i + 1]));
        min_diff = min(min_diff, diff);
    }
    return min_diff;
  }
};





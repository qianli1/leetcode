#include <vector>
#include <queue>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _630_CourseScheduleIII {
    /**
    * 630. Course Schedule III
    * There are n different online courses numbered from 1 to n. Each course has some duration(course length) t and closed on dth day. 
    * A course should be taken continuously for t days and must be finished before or on the dth day. You will start at the 1st day.

    Given n online courses represented by pairs (t,d), your task is to find the maximal number of courses that can be taken.

    Example:

    Input: [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
    Output: 3
    Explanation: 
    There're totally 4 courses, but you can take 3 courses at most:
    First, take the 1st course, it costs 100 days so you will finish it on the 100th day, and ready to take the next course on the 101st day.
    Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, and ready to take the next course on the 1101st day. 
    Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day. 
    The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.

    time : O(n*logn);
    space : O(n);
    */
 
 public:
  int scheduleCourse(vector<vector<int>>& courses) {
    sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) {return a[1] < b[1];});
    priority_queue<int> q;
    int time = 0;
    for (int i = 0; i < courses.size(); i++) {
        q.push(courses[i][0]);
        time += courses[i][0];
        if (time > courses[i][1]) {
            time -= q.top();
            q.pop();
        }
    }
    return q.size();
  }
};





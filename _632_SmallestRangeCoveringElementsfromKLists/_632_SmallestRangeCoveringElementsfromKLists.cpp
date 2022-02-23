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

class _632_SmallestRangeCoveringElementsfromKLists {
    /**
    * 632. Smallest Range Covering Elements from K Lists
    * You have k lists of sorted integers in ascending order. Find the smallest range that includes at least one number from each of the k lists.

    We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.

    Example 1:

    Input: [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
    Output: [20,24]
    Explanation: 
    List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
    List 2: [0, 9, 12, 20], 20 is in range [20,24].
    List 3: [5, 18, 22, 30], 22 is in range [20,24].
    
    */
 
 public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    vector<vector<int>> points;
    for (int i = 0; i < nums.size(); i++) {
        for (int num : nums[i]) {
            points.push_back({num, i});
        }
    }
    sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    });
    vector<int> list(nums.size());
    int count = 0;
    int start = -1;
    int length = INT_MAX;
    
    for (int i = 0, j = 0; j < points.size(); j++) {
        if (list[points[j][1]]++ == 0) {
            count++;
        }
        while (count == list.size()) {
            if (points[j][0] - points[i][0] < length) {
                start = points[i][0];
                length = points[j][0] - points[i][0];
            }
            int prev = points[i][0];
            while (i <= j && prev == points[i][0]) {
                if (--list[points[i++][1]] == 0) {
                    count--;
                }
            }
        }
    }
    return {start, start + length};
  }

  vector<int> smallestRange2(vector<vector<int>>& nums) {
    int maximum = nums[0][0];
    priority_queue<vector<int>, vector<vector<int>>, compare> q;
    for (int i = 0; i < nums.size(); i++) {
        q.push({nums[i][0], i, 0});
        maximum = max(maximum, nums[i][0]);
    }
    int length = INT_MAX;
    int start = -1;
    while (q.size() == nums.size()) {
        auto cur = q.top();
        q.pop();
        if (maximum - cur[0] < length) {
            length = maximum - cur[0];
            start = cur[0];
        }
        
        if (cur[2] + 1 < nums[cur[1]].size()) {
            cur[0] = nums[cur[1]][cur[2] + 1];
            cur[2]++;
            q.push(cur);
            maximum = max(maximum, cur[0]);
        }
    }
    return {start, start + length};
  }

 private:
  struct compare {
    bool operator()(vector<int>& p, vector<int>& q) {
        return p[0] > q[0];
    }
  }; 
};





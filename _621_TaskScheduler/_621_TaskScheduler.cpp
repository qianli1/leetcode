#include <vector>
#include <queue>
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

class _621_TaskScheduler {
    /**
    * 621. Task Scheduler
    * You are given a char array representing tasks CPU need to do. It contains capital letters A to Z where each letter 
    * represents a different task. Tasks could be done without the original order of the array. Each task is done in one 
    * unit of time. For each unit of time, the CPU could complete either one task or just be idle.

    However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter 
    in the array), that is that there must be at least n units of time between any two same tasks.

    You need to return the least number of units of times that the CPU will take to finish all the given tasks.    

    Example 1:

    Input: tasks = ["A","A","A","B","B","B"], n = 2
    Output: 8
    Explanation: 
    A -> B -> idle -> A -> B -> idle -> A -> B
    There is at least 2 units of time between any two same tasks.
    Example 2:

    Input: tasks = ["A","A","A","B","B","B"], n = 0
    Output: 6
    Explanation: On this case any permutation of size 6 would work since n = 0.
    ["A","A","A","B","B","B"]
    ["A","B","A","B","A","B"]
    ["B","B","B","A","A","A"]
    ...
    And so on.
    Example 3:

    Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
    Output: 16
    Explanation: 
    One possible solution is
    A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
    */
 
 public:
  //time: O(最终结果)
  int leastInterval(vector<char>& tasks, int n) {
    vector<int> map(26);
    for (char task : tasks) {
        map[task - 'A']++;
    }
    priority_queue<int> pq;
    for (int freq : map) {
        if (freq > 0) {
            pq.push(freq);
        }
    }
    
    int res = 0;
    while (!pq.empty()) {
        int i = 0;
        vector<int> temp;
        while (i <= n) {
            if (!pq.empty()) {
                if (pq.top() > 1) {
                    temp.push_back(pq.top() - 1);
                    pq.pop();
                } else {
                    pq.pop();
                }
            }
            res++;
            if (pq.empty() && temp.size() == 0) {
                break;
            }
            i++;
        } 
        for (auto t : temp) {
            pq.push(t);
        }
    }
    return res;
  }

  //time: O(最终结果)
  int leastInterval2(vector<char>& tasks, int n) {
    vector<int> map(26);
    for (char task : tasks) {
        map[task - 'A']++;
    }
    sort(map.begin(), map.end());
    int res = 0;
    
    while (map[25] > 0) {
        int i = 0;
        while (i <= n) {
            if (map[25] == 0) {
                break;
            }
            if (i < 26 && map[25 - i] > 0) {
                map[25 - i]--;
            }
            res++;
            i++;
        }
        sort(map.begin(), map.end());
    }
    return res;
  }

  // O(任务总数)
  int leastInterval3(vector<char>& tasks, int n) {
    vector<int> map(26);
    for (char task : tasks) {
        map[task - 'A']++;
    }
    sort(map.begin(), map.end());
    
    int max_val = map[25] - 1;
    int slots = max_val * n;
    for (int i = 24; i >= 0 && map[i] > 0; i--) {
        slots -= min(map[i], max_val);
    }
    return slots > 0 ? slots + tasks.size() : tasks.size();
  }
};





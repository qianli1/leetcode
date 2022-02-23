#include <vector>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _636_ExclusiveTimeofFunctions {
    /**
    * 636. Exclusive Time of Functions
    * On a single threaded CPU, we execute some functions.  Each function has a unique id between 0 and N-1.

    We store logs in timestamp order that describe when a function is entered or exited.

    Each log is a string with this format: "{function_id}:{"start" | "end"}:{timestamp}".  For example, "0:start:3" means the 
    function with id 0 started at the beginning of timestamp 3.  "1:end:2" means the function with id 1 ended at the end of 
    timestamp 2.

    A function's exclusive time is the number of units of time spent in this function.  Note that this does not include any 
    recursive calls to child functions.

    The CPU is single threaded which means that only one function is being executed at a given time unit.

    Return the exclusive time of each function, sorted by their function id.

    Example 1:
    Input:
    n = 2
    logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
    Output: [3, 4]
    Explanation:
    Function 0 starts at the beginning of time 0, then it executes 2 units of time and reaches the end of time 1.
    Now function 1 starts at the beginning of time 2, executes 4 units of time and ends at time 5.
    Function 0 is running again at the beginning of time 6, and also ends at the end of time 6, thus executing for 1 unit of time. 
    So function 0 spends 2 + 1 = 3 units of total time executing, and function 1 spends 4 units of total time executing.

    time : O(n);
    space : O(n);
    */
 
 public:
  vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> res(n);
    stack<vector<int>> st;
    
    for (string log : logs) {
        vector<string> thread;
        stringstream ss(log);
        string t;
        while (!ss.eof()) {
            getline(ss, t, ':');
            if (t == "") continue;
            thread.push_back(t);
        }
        int index = stoi(thread[0]);
        int time = stoi(thread[2]);
        
        if (thread[1] == "start") {
            st.push({index, time});
        } else {
            int running = time - st.top()[1] + 1;
            st.pop();
            res[index] += running;
            if (!st.empty()) {
                auto tmp = st.top();
                st.pop();
                res[tmp[0]] -= running;
                st.push(tmp);
            }
        }
    }
    return res;
  }
};





#include <vector>
#include <string> 
#include <unordered_map>
#include <map>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _635_DesignLogStorageSystem2 {
    /**
    * 635. Design Log Storage System
    * You are given several logs that each log contains a unique id and timestamp. Timestamp is a string that has the following 
    * format: Year:Month:Day:Hour:Minute:Second, for example, 2017:01:01:23:59:59. All domains are zero-padded decimal numbers.

    Design a log storage system to implement the following functions:

    void Put(int id, string timestamp): Given a log's unique id and timestamp, store the log in your storage system.

    int[] Retrieve(String start, String end, String granularity): Return the id of logs whose timestamps are within the range from 
    start to end. Start and end all have the same format as timestamp. However, granularity means the time level for consideration. 
    For example, start = "2017:01:01:23:59:59", end = "2017:01:02:23:59:59", granularity = "Day", it means that we need to find the 
    logs within the range from Jan. 1st 2017 to Jan. 2nd 2017.

    Example 1:
    put(1, "2017:01:01:23:59:59");
    put(2, "2017:01:01:22:59:59");
    put(3, "2016:01:01:00:00:00");
    retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Year"); // return [1,2,3], because you need to return all logs within 
    2016 and 2017.
    retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour"); // return [1,2], because you need to return all logs start from 
    2016:01:01:01 to 2017:01:01:23, where log 3 is left outside the range.
    Note:
    There will be at most 300 operations of Put or Retrieve.
    Year ranges from [2000,2017]. Hour ranges from [00,23].
    Output for Retrieve has no order required.
    */
 
 private:
  multimap<string, int> treemap;
  unordered_map<string, int> mp;
  string minimum = "2000:01:01:00:00:00";
  string maximum = "2017:12:31:23:59:59";

 public:
  LogSystem() {
    mp["Year"] = 4;
    mp["Month"] = 7;
    mp["Day"] = 10;
    mp["Hour"] = 13;
    mp["Minute"] = 16;
    mp["Second"] = 19;
  }

  void put(int id, string timestamp) {
    treemap.emplace(timestamp, id);
  }

  vector<int> retrieve(string s, string e, string gra) {
    int index = mp[gra];
    vector<int> res;
    string start = s.substr(0, index) + minimum.substr(index);
    string end = e.substr(0, index) + maximum.substr(index);
    auto first = treemap.lower_bound(start);
    auto last  = treemap.upper_bound(end);
    for (auto it = first; it != last; it++)
        res.push_back(it->second);
    return res;
  }
};





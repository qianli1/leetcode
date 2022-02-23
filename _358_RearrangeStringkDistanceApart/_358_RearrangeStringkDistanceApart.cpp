#include <vector>
#include <string>
#include <unordered_map>
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

struct compare{
  bool operator()(pair<int, char>& p1, pair<int, char>& p2){
    if (p1.first == p2.first) {
        return p1.second > p2.second;
    }
    return p1.first < p2.first;
  }
};

class _358_RearrangeStringkDistanceApart {
    /**
    * 358. Rearrange String k Distance Apart
    * Given a non-empty string s and an integer k, rearrange the string such that the same characters are at least 
    * distance k from each other.

    All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty 
    string "".

    Example 1:

    Input: s = "aabbcc", k = 3
    Output: "abcabc" 
    Explanation: The same letters are at least distance 3 from each other.
    Example 2:

    Input: s = "aaabc", k = 3
    Output: "" 
    Explanation: It is not possible to rearrange the string.
    Example 3:

    Input: s = "aaadbbcc", k = 2
    Output: "abacabcd"
    Explanation: The same letters are at least distance 2 from each other.

    */
 
 public:
  //time: O(n), space: O(n)
  string rearrangeString(string s, int k) {
    if (s.empty() || s.size() == 0) {
        return s;
    }
    vector<int> count(26);
    vector<int> valid(26);
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        count[c - 'a']++;
    }
    string res;
    for (int i = 0; i < s.size(); i++) {
        int next = findNext(count, valid, i);
        if (next == -1) {
            return "";
        }
        res += ((char)('a' + next));
        valid[next] = i + k;
        count[next]--;
    }
    return res;
  }

  int findNext(vector<int>& count, vector<int>& valid, int index) {
    int max = 0, res = - 1;
    for (int i = 0; i < count.size(); i++) {
        if (count[i] > max && valid[i] <= index) {
            res = i;
            max = count[i];
        }
    }
    return res;
  }

  //Time: O(nlogn), space: O(n)
  string rearrangeString2(string s, int k) {
    unordered_map<char, int> mp;
    for (char c : s) {
        mp[c]++;
    }
    priority_queue<pair<int, char>, vector<pair<int, char>>, compare> pq;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        pq.push(make_pair(it->second, it->first));
    }
    queue<pair<int, char>> q;
    string res = "";
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        res += cur.second;
        cur.first--;
        q.push(cur);
        if (q.size() < k) continue;
        auto front = q.front();
        q.pop();
        if (front.first > 0) {
            pq.push(front);
        }
    }
    return res.size() == s.size() ? res : ""; 
  }
};





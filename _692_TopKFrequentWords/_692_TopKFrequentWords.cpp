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

class _692_TopKFrequentWords {
    /**
    * 692. Top K Frequent Words
    * Given a non-empty list of words, return the k most frequent elements.

    Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with 
    the lower alphabetical order comes first.

    Example 1:
    Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
    Output: ["i", "love"]
    Explanation: "i" and "love" are the two most frequent words.
        Note that "i" comes before "love" due to a lower alphabetical order.
    Example 2:
    Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
    Output: ["the", "is", "sunny", "day"]
    Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
        with the number of occurrence being 4, 3, 2 and 1 respectively.
    Note:
    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Input words contain only lowercase letters.

    Time: O(n)
    Space: O(n)
    */
 
struct compare {
  bool operator()( pair<int, string> const& a,  pair<int, string> const& b) { 
    if(a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
  } 
}; 


  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> mp;
    for (string word : words) {
        mp[word]++;
    }
    
    priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;  
    for(auto& v : mp)
        pq.push({v.second, v.first});
    
    vector<string> res;
    while(k)
    {
        res.push_back(pq.top().second);
        pq.pop();
        k--;
    }
    
    return res;
  }
};





#include <vector>
#include <queue>
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

class _347_TopKFrequentElements {
    /**
    * 347. Top K Frequent Elements
    * Given a non-empty array of integers, return the k most frequent elements.

    Example 1:

    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]
    Example 2:

    Input: nums = [1], k = 1
    Output: [1]
    Note:

    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
    It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
    You can return the answer in any order.
    */
 
 public:
  //Priority Queue : time : O(klogn) space : O(n)
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    for (int num : nums) {
        map[num]++;
    }
    priority_queue<pair<int, int>> maxHeap;
    for (auto it = map.begin(); it != map.end(); it++) {
        maxHeap.push(make_pair(it->second, it->first));
    }
    vector<int> res;
    while (res.size() < k) {
        res.push_back(maxHeap.top().second);
        maxHeap.pop();
    }
    return res;
  }

  //TreeMap : time : O(klogn) space : O(n)
  vector<int> topKFrequent2(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for (int num : nums) {
        mp[num]++;
    }
    map<int, vector<int>> freq_map;
    for (auto m : mp) {
        freq_map[m.second].push_back(m.first);
    }
    vector<int> res;

    for (auto it = freq_map.rbegin(); it != freq_map.rend() && res.size() < k; it++) {
        for (int num : it->second) {
            res.push_back(num);
            if (res.size() == k) break;
        }
    } 
    return res;
  }

  //Bucket sort : time : O(n) space : O(n)
  vector<int> topKFrequent3(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    for (int num : nums) {
        map[num]++;
    }
    vector<vector<int>> bucket(nums.size() + 1);
    for (auto m : map) {
        bucket[m.second].push_back(m.first);
    }
    vector<int> res;
    for (int i = bucket.size() - 1; i >= 0 && res.size() < k; i--) {
        for (int num : bucket[i]) {
            res.push_back(num);
            if (res.size() == k) break;
        }
    }
    return res;
  }
};





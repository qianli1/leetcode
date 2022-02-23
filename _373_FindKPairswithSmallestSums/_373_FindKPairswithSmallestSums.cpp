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
struct compare 
{
  bool operator()(const vector<int>& a, const vector<int>& b) {
    return a[0] + a[1] > b[0] + b[1];
  }    
};

class _373_FindKPairswithSmallestSums {
    /**
    * 373. Find K Pairs with Smallest Sums
    * You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

    Define a pair (u,v) which consists of one element from the first array and one element from the second array.

    Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

    Example 1:

    Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
    Output: [[1,2],[1,4],[1,6]] 
    Explanation: The first 3 pairs are returned from the sequence: 
                [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
    Example 2:

    Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
    Output: [1,1],[1,1]
    Explanation: The first 2 pairs are returned from the sequence: 
                [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
    Example 3:

    Input: nums1 = [1,2], nums2 = [3], k = 3
    Output: [1,3],[2,3]
    Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]

    time : O(klogk);
    space : O(k);
    */
 
 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>> res;
    if (nums1.empty() || nums2.empty() || k <= 0) {
        return res;
    }
    priority_queue<vector<int>, vector<vector<int>>, compare > pq;
    for (int i = 0; i < nums1.size() && i < k; i++) {
        pq.push({nums1[i], nums2[0], 0});
    }
    while (!pq.empty() && k-- > 0) {
        auto cur = pq.top();
        pq.pop();
        res.push_back({cur[0], cur[1]});
        if (cur[2] == nums2.size() - 1) continue;
        pq.push({cur[0], nums2[cur[2] + 1], cur[2] + 1});
    }
    return res;
  }
};





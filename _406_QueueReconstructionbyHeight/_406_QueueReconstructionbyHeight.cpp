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

class _406_QueueReconstructionbyHeight {
    /**
    * 406. Queue Reconstruction by Height
    * Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), 
    * where h is the height of the person and k is the number of people in front of this person who have a height greater 
    * than or equal to h. Write an algorithm to reconstruct the queue.

    Note:
    The number of people is less than 1,100.

    
    Example

    Input:
    [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

    Output:
    [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

    time : O(n^2);
    space : O(n);
    */
 
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    vector<vector<int>> res;
    if (people.empty() || people.size() == 0 || people[0].size() == 0) {
        return res;
    }
    auto comp = [](const vector<int>& p1, const vector<int>& p2) { 
        return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]); 
    };
    
    sort(people.begin(), people.end(), comp);
    for (auto& p : people) 
        res.insert(res.begin() + p[1], p);
    return res;
  }
};





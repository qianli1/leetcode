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

class _703_KthLargestElementinaStream {
    /**
    * 703. Kth Largest Element in a Stream
    * Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, 
    * not the kth distinct element.

    Your KthLargest class will have a constructor which accepts an integer k and an integer array nums, which contains initial 
    elements from the stream. For each call to the method KthLargest.add, return the element representing the kth largest element 
    in the stream.

    Example:

    int k = 3;
    int[] arr = [4,5,8,2];
    KthLargest kthLargest = new KthLargest(3, arr);
    kthLargest.add(3);   // returns 4
    kthLargest.add(5);   // returns 5
    kthLargest.add(10);  // returns 5
    kthLargest.add(9);   // returns 8
    kthLargest.add(4);   // returns 8

    time : O(nlogk);
    space : O(k);
    */
 
 public:
  priority_queue<int, vector<int>, greater<int>> q;
  int size;

  KthLargest(int k, vector<int>& nums) {
    size = k;
    for (int i = 0; i < nums.size(); i++) {
        q.push(nums[i]);
        if (q.size() > k) q.pop();
    }
  }

  int add(int val) {
    q.push(val);
    if (q.size() > size) q.pop();
    return q.top();   
  }
};





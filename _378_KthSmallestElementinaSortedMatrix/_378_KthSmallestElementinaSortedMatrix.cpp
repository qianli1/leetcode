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
struct Tuple 
{
  int x, y, val;
  Tuple(int _x, int _y, int _val) : x(_x), y(_y), val(_val) {}
  friend bool operator< (const Tuple& a, const Tuple& b) {
    return a.val > b.val;
  }    
};

class _378_KthSmallestElementinaSortedMatrix {
    /**
    * 378. Kth Smallest Element in a Sorted Matrix
    * Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

    Note that it is the kth smallest element in the sorted order, not the kth distinct element.

    Example:

    matrix = [
    [ 1,  5,  9],
    [10, 11, 13],
    [12, 13, 15]
    ],
    k = 8,

    return 13.
    */
 
 public:
   //priority queue: time: O(nlogn), space: O(n)
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<Tuple, vector<Tuple>> pq;
    for (int i = 0; i < matrix.size(); i++) {
        pq.push(Tuple(0, i, matrix[0][i]));
    }
    for (int i = 0; i < k - 1; i++) {
        Tuple tuple = pq.top();
        pq.pop();
        if (tuple.x == matrix.size() - 1) continue;
        pq.push(Tuple(tuple.x + 1, tuple.y, matrix[tuple.x + 1][tuple.y]));
    }
    return pq.top().val;
  }

  //binary search: time: O(n * log(max - min)), space: O(1)
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int left = matrix[0][0], right = matrix[n - 1][n - 1];
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        int num = count(matrix, mid);
        if (num >= k) right = mid;
        else left = mid;
    }
    if (count(matrix, right) <= k - 1) return right;
    return left;
  }

  int count(vector<vector<int>> &matrix, int target) {
    int n = matrix.size();
    int res = 0;
    int i = n - 1, j = 0; 
    while (i >= 0 && j < n) {
        if (matrix[i][j] < target) {
            res += i + 1;
            j++;
        }
        else {
            i--;
        }
    }
    return res;
  }
};





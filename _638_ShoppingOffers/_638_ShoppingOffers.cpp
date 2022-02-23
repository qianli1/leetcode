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

class _638_ShoppingOffers {
    /**
    * 638. Shopping Offers
    * In LeetCode Store, there are some kinds of items to sell. Each item has a price.

    However, there are some special offers, and a special offer consists of one or more different kinds of items with a sale price.

    You are given the each item's price, a set of special offers, and the number we need to buy for each item. The job is to output 
    the lowest price you have to pay for exactly certain items as given, where you could make optimal use of the special offers.

    Each special offer is represented in the form of an array, the last number represents the price you need to pay for this special 
    offer, other numbers represents how many specific items you could get if you buy this offer.

    You could use any of special offers as many times as you want.

    Example 1:
    Input: [2,5], [[3,0,5],[1,2,10]], [3,2]
    Output: 14
    Explanation: 
    There are two kinds of items, A and B. Their prices are $2 and $5 respectively. 
    In special offer 1, you can pay $5 for 3A and 0B
    In special offer 2, you can pay $10 for 1A and 2B. 
    You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2), and $4 for 2A.
    Example 2:
    Input: [2,3,4], [[1,1,0,4],[2,2,1,9]], [1,2,1]
    Output: 11
    Explanation: 
    The price of A is $2, and $3 for B, $4 for C. 
    You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C. 
    You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special offer #1), and $3 for 1B, $4 for 1C. 
    You cannot add more items, though only $9 for 2A ,2B and 1C.
    */
 
 public:
  int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    return helper(price, special, needs, 0);
  }

  int helper(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int pos) {
    int res = maximize(price, needs);
    for (int i = pos; i < special.size(); i++) {
        vector<int> offer = special[i];
        vector<int> temp;
        for (int j = 0; j < needs.size(); j++) {
            if (needs[j] < offer[j]) {
                temp.clear();
                break;
            }
            temp.push_back(needs[j] - offer[j]);
        }
        if (!temp.empty()) {
            res = min(res, offer.back() + helper(price, special, temp, i));
        }
    }
    return res;
  }

  int maximize(vector<int>& price, vector<int>& needs) {
    int total = 0;
    for (int i = 0; i < needs.size(); i++) {
        total += price[i] * needs[i];
    }
    return total;
  }
};





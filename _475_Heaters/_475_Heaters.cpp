#include <vector>
#include <set>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _475_Heaters {
    /**
    * 475. Heaters
    * Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

    Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could 
    be covered by those heaters.

    So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.

    Note:

    Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
    Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
    As long as a house is in the heaters' warm radius range, it can be warmed.
    All the heaters follow your radius standard and the warm radius will the same.

    Example 1:

    Input: [1,2,3],[2]
    Output: 1
    Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
 

    Example 2:

    Input: [1,2,3,4],[1,4]
    Output: 1
    Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.
    
    time : O(m * n);
    space : O(1);
    * @param houses
    * @param heaters
    * @return
    */
 
 public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    int radius = 0;
    int index = 0;
    for (int i = 0; i < houses.size(); i++){
        while (index + 1 < heaters.size() && (abs(heaters[index + 1] - houses[i]) <= abs(heaters[index] - houses[i]))) {
            index++;
        }
        radius = max (radius, abs(heaters[index] - houses[i]));
    }
    
    return radius;
  }

  int findRadius2(vector<int>& houses, vector<int>& heaters) {
    sort(heaters.begin(), heaters.end());
    int res = 0;
    for(int i = 0; i < houses.size(); i++){
        // Binary search
        int l = 0;
        int r = heaters.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if (heaters[mid] == houses[i]){
                l = mid - 1;
                r = mid + 1;
                break;
            } else if (heaters[mid] < houses[i]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }                    
        }
        double index = (l + r) / 2.0;
        int right = (index > heaters.size() - 1)? INT_MAX : heaters[(int)(index + 0.5)] - houses[i];
        int left = (index < 0)? INT_MAX : houses[i] - heaters[(int)index];
        res = max(res, min(right, left));
    }
    return res;
  }

  int findRadius3(vector<int>& houses, vector<int>& heaters) {
    set<int> s;
    for (int heater : heaters) {
        s.insert(heater);
    }
    int index = 0, res = 0;
    for (int house : houses) {
        int dist1 = s.lower_bound(house) == s.end() ? INT_MAX : *s.lower_bound(house) - house;
        int dist2 = s.lower_bound(house) == s.begin() ? INT_MAX : house - *(--s.lower_bound(house));
        res = max(res, min(dist1, dist2));
    }
    return res;
    
  }
};





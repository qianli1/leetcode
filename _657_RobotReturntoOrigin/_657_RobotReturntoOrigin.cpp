#include <vector>
#include <string>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _657_RobotReturntoOrigin {
    /**
    * 657. Robot Return to Origin
    * There is a robot starting at position (0, 0), the origin, on a 2D plane. Given a sequence of its moves, judge if this 
    * robot ends up at (0, 0) after it completes its moves.

    The move sequence is represented by a string, and the character moves[i] represents its ith move. Valid moves are R (right), 
    L (left), U (up), and D (down). If the robot returns to the origin after it finishes all of its moves, return true. Otherwise, 
    return false.

    Note: The way that the robot is "facing" is irrelevant. "R" will always make the robot move to the right once, "L" will always 
    make it move left, etc. Also, assume that the magnitude of the robot's movement is the same for each move.

    Example 1:

    Input: "UD"
    Output: true 
    Explanation: The robot moves up once, and then down once. All moves have the same magnitude, so it ended up at the origin where 
    it started. Therefore, we return true.
    

    Example 2:

    Input: "LL"
    Output: false
    Explanation: The robot moves left twice. It ends up two "moves" to the left of the origin. We return false because it is not at 
    the origin at the end of its moves.

    time : O(n);
    space : O(1);
    */
 
 public:
  bool judgeCircle(string moves) {
    int x = 0;
    int y = 0;
    for (char ch : moves) {
        if (ch == 'U') y++;
        else if (ch == 'D') y--;
        else if (ch == 'R') x++;
        else if (ch == 'L') x--;
    }
    return x == 0 && y ==0;
  }
};





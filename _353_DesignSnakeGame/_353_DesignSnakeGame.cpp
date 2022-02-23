#include <vector>
#include <string>
#include <unordered_set>
#include <deque>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _353_DesignSnakeGame {
    /**
    * 353. Design Snake Game
    * Design a Snake game that is played on a device with screen size = width x height. Play the game online if you are not familiar with the game.

    The snake is initially positioned at the top left corner (0,0) with length = 1 unit.

    You are given a list of food's positions in row-column order. When a snake eats the food, its length and the game's score both increase by 1.

    Each food appears one by one on the screen. For example, the second food will not appear until the first food was eaten by the snake.

    When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake.

    Example:

    Given width = 3, height = 2, and food = [[1,2],[0,1]].

    Snake snake = new Snake(width, height, food);

    Initially the snake appears at position (0,0) and the food at (1,2).

    |S| | |
    | | |F|

    snake.move("R"); -> Returns 0

    | |S| |
    | | |F|

    snake.move("D"); -> Returns 0

    | | | |
    | |S|F|

    snake.move("R"); -> Returns 1 (Snake eats the first food and right after that, the second food appears at (0,1) )

    | |F| |
    | |S|S|

    snake.move("U"); -> Returns 1

    | |F|S|
    | | |S|

    snake.move("L"); -> Returns 2 (Snake eats the second food)

    | |S|S|
    | | |S|

    snake.move("U"); -> Returns -1 (Game over because snake collides with border)
    */
 
 private:
  unordered_set<int> set;
  deque<int> dq;
  int score;
  int food_index;
  int width;
  int height;
  vector<vector<int>> food;
        
 public:
  /** Initialize your data structure here.
    @param width - screen width
    @param height - screen height 
    @param food - A list of food positions
    E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
  SnakeGame(int width, int height, vector<vector<int>>& food) {
    this->width = width;
    this->height = height;
    this->food = food;
    score = 0;
    food_index = 0;
    set.insert(0);
    dq.push_back(0);
    
  }

  /** Moves the snake.
    @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
    @return The game's score after the move. Return -1 if game over. 
    Game over when snake crosses the screen boundary or bites its body. */
  int move(string direction) {
    if (score == -1) {
        return -1;
    }
    int row_head = dq.front() / width;
    int col_head = dq.front() % width;
    
    if (direction == "U") {
        row_head--;
    } else if (direction == "D") {
        row_head++;
    } else if (direction == "L") {
        col_head--;
    } else if (direction == "R") {
        col_head++;
    }

    int head = row_head * width + col_head;
    set.erase(dq.back());
    if (row_head < 0 || row_head  == height || col_head < 0 || col_head == width ||set.count(head)) {
        return score = -1;
    }
    set.insert(head);
    dq.push_front(head);
    if (food_index < food.size() && row_head == food[food_index][0] && col_head == food[food_index][1]) {
        food_index++;
        score++;
        set.insert(dq.back());
        return score;
    }
    dq.pop_back();
    return score;
  }
};





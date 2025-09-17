// 2025-09-17 20:36:18

#include <bits/stdc++.h>

using namespace std;

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public:
    enum class Direction { NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3 };

    static constexpr int NUM_DIRECTIONS = 4;

    struct Agent {
        int x;
        int y;
        int moves = 0;
        Direction origin_direction;
        Direction current_direction;
        const array<pair<int, int>, NUM_DIRECTIONS> delta_coords = {
            std::make_pair(0, 1), // NORTH: (dx=0, dy=1)
            std::make_pair(1, 0), // EAST:  (dx=1, dy=0)
            std::make_pair(0, -1), // SOUTH: (dx=0, dy=-1)
            std::make_pair(-1, 0) // WEST:  (dx=-1, dy=0)
        };

        Agent(int start_x, int start_y, Direction start_dir) :
            x(start_x), y(start_y), origin_direction(start_dir), current_direction(start_dir) {}

        void turnLeft() {
            int current_dir_int = static_cast<int>(current_direction);
            current_dir_int = (current_dir_int - 1 + NUM_DIRECTIONS) % NUM_DIRECTIONS;
            current_direction = static_cast<Direction>(current_dir_int);
        }

        void turnRight() {
            int current_dir_int = static_cast<int>(current_direction);
            current_dir_int = (current_dir_int + 1) % NUM_DIRECTIONS;
            current_direction = static_cast<Direction>(current_dir_int);
        }

        void moveForward() {
            int dir_idx = static_cast<int>(current_direction);
            x += delta_coords[dir_idx].first;
            y += delta_coords[dir_idx].second;
            moves++;
        }

        bool isOrigin() { return x == 0 && y == 0 && current_direction == origin_direction; }

        bool noMoves() { return moves == 0; }

        pair<int, int> getCoordinates() const { return {x, y}; }
    };

    bool isRobotBounded(string instructions) {
        Agent p(0, 0, Direction::NORTH);

        for (int i = 0; i < 4; i++) {
            for (auto s : instructions) {
                switch (s) {
                    case 'G':
                        p.moveForward();
                        break;
                    case 'L':
                        p.turnLeft();
                        break;
                    case 'R':
                        p.turnRight();
                        break;
                }
            }
            if (p.isOrigin() || p.noMoves()) {
                return true;
            }
        }
        return false;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

#include "../../../utils.h"

int main(void) {
    Solution s;
    cout << s.isRobotBounded("GLGLGGLGL") << endl; // false
    cout << s.isRobotBounded("LRRRRLLLRL"); // true
    return 0;
}

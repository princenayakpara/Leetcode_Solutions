// Last updated: 05/05/2026, 08:45:46
1class Solution {
2public:
3    bool judgeCircle(string moves) {
4        int x = 0, y = 0;
5
6        for (char move : moves) {
7            if (move == 'U') y++;
8            else if (move == 'D') y--;
9            else if (move == 'L') x--;
10            else if (move == 'R') x++;
11        }
12
13        return x == 0 && y == 0;
14    }
15};
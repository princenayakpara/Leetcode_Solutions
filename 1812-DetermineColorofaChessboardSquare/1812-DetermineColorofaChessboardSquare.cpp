// Last updated: 27/05/2026, 02:53:58
1class Solution {
2public:
3    bool judgeCircle(string moves) {
4        int x =0, y = 0;
5        for(char c: moves){
6            if(c=='U')y++;
7            else if(c=='D')y--;
8            else if(c=='R')x++;
9            else if(c=='L')x--;
10        }
11        return x == 0 && y == 0;
12    }
13};
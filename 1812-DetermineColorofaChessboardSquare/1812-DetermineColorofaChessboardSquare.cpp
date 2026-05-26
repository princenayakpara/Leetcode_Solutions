// Last updated: 27/05/2026, 02:19:18
1class Solution {
2public:
3    bool squareIsWhite(string coordinates) {
4        int col = coordinates[0]-'a';
5        int row = coordinates[1]-'0';
6        return (col + row) % 2== 0;
7    }
8};
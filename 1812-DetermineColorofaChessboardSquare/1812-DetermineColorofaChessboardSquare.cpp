// Last updated: 27/05/2026, 02:20:45
1class Solution {
2public:
3    bool squareIsWhite(string coordinates) {
4        return (coordinates[0] + coordinates[1]) % 2 != 0;
5    }
6};
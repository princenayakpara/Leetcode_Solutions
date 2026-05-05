// Last updated: 05/05/2026, 07:34:38
1class Solution {
2public:
3    bool squareIsWhite(string coordinates) {
4        return (coordinates[0] + coordinates[1]) % 2 == 1;
5    }
6};
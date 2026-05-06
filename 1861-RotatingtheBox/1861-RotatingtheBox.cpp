// Last updated: 06/05/2026, 23:54:20
1class Solution {
2public:
3    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
4        int m = boxGrid.size();
5        int n = boxGrid[0].size();
6
7        for (int i = 0; i < m; i++) {
8            int empty = n - 1;
9
10            for (int j = n - 1; j >= 0; j--) {
11                if (boxGrid[i][j] == '*') {
12                    empty = j - 1;
13                }
14                else if (boxGrid[i][j] == '#') {
15                    swap(boxGrid[i][j], boxGrid[i][empty]);
16                    empty--;
17                }
18            }
19        }
20
21        vector<vector<char>> result(n, vector<char>(m));
22
23        for (int i = 0; i < m; i++) {
24            for (int j = 0; j < n; j++) {
25                result[j][m - 1 - i] = boxGrid[i][j];
26            }
27        }
28
29        return result;
30    }
31};
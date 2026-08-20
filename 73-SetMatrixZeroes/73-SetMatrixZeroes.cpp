// Last updated: 20/08/2026, 15:39:55
1class Solution {
2public:
3    void setZeroes(vector<vector<int>>& matrix) {
4        int m = matrix.size();
5        int n = matrix[0].size();
6
7        bool firstRow = false;
8        bool firstCol = false;
9
10        for (int j = 0; j < n; j++)
11            if (matrix[0][j] == 0)
12                firstRow = true;
13
14        for (int i = 0; i < m; i++)
15            if (matrix[i][0] == 0)
16                firstCol = true;
17
18        for (int i = 1; i < m; i++) {
19            for (int j = 1; j < n; j++) {
20                if (matrix[i][j] == 0) {
21                    matrix[i][0] = 0;
22                    matrix[0][j] = 0;
23                }
24            }
25        }
26
27        for (int i = 1; i < m; i++) {
28            for (int j = 1; j < n; j++) {
29                if (matrix[i][0] == 0 || matrix[0][j] == 0)
30                    matrix[i][j] = 0;
31            }
32        }
33
34        if (firstRow) {
35            for (int j = 0; j < n; j++)
36                matrix[0][j] = 0;
37        }
38
39        if (firstCol) {
40            for (int i = 0; i < m; i++)
41                matrix[i][0] = 0;
42        }
43    }
44};
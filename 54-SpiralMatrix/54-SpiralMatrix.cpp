// Last updated: 12/03/2026, 12:09:26
1class Solution {
2public:
3    vector<int> spiralOrder(vector<vector<int>>& matrix) {
4        int top = 0;
5        int bottom = matrix.size() - 1;
6        int left = 0;
7        int right = matrix[0].size() - 1;
8        vector<int> res;
9           while (top <= bottom && left <= right) {
10
11            for (int i = left; i <= right; i++) {
12                res.push_back(matrix[top][i]);
13            }
14            top++;
15
16            for (int i = top; i <= bottom; i++) {
17                res.push_back(matrix[i][right]);
18            }
19            right--;
20
21            if (top <= bottom) {
22                for (int i = right; i >= left; i--) {
23                    res.push_back(matrix[bottom][i]);
24                }
25                bottom--;
26            }
27
28            if (left <= right) {
29                for (int i = bottom; i >= top; i--) {
30                    res.push_back(matrix[i][left]);
31                }
32                left++;
33            }
34        } return res;
35    }
36};
// Last updated: 21/08/2026, 14:51:18
1class Solution {
2public:
3    vector<int> spiralOrder(vector<vector<int>>& matrix) {
4        vector<int> ans;
5
6        int top = 0;
7        int bottom = matrix.size() - 1;
8        int left = 0;
9        int right = matrix[0].size() - 1;
10
11        while (top <= bottom && left <= right) {
12            for (int j = left; j <= right; j++)
13                ans.push_back(matrix[top][j]);
14            top++;
15
16            for (int i = top; i <= bottom; i++)
17                ans.push_back(matrix[i][right]);
18            right--;
19
20            if (top <= bottom) {
21                for (int j = right; j >= left; j--)
22                    ans.push_back(matrix[bottom][j]);
23                bottom--;
24            }
25
26            if (left <= right) {
27                for (int i = bottom; i >= top; i--)
28                    ans.push_back(matrix[i][left]);
29                left++;
30            }
31        }
32
33        return ans;
34    }
35};
// Last updated: 20/08/2026, 15:20:18
1class Solution {
2public:
3    bool isValidSudoku(vector<vector<char>>& board) {
4        bool row[9][9] = {};
5        bool col[9][9] = {};
6        bool box[9][9] = {};
7
8        for (int i = 0; i < 9; i++) {
9            for (int j = 0; j < 9; j++) {
10                if (board[i][j] == '.')
11                    continue;
12
13                int num = board[i][j] - '1';
14                int boxIndex = (i / 3) * 3 + (j / 3);
15
16                if (row[i][num] || col[j][num] || box[boxIndex][num])
17                    return false;
18
19                row[i][num] = true;
20                col[j][num] = true;
21                box[boxIndex][num] = true;
22            }
23        }
24
25        return true;
26    }
27};
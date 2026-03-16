// Last updated: 16/03/2026, 23:59:07
1class Solution {
2public:
3    vector<int> getBiggestThree(vector<vector<int>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6        
7        set<int> sums;
8
9        for(int i = 0; i < m; i++){
10            for(int j = 0; j < n; j++){
11                
12                sums.insert(grid[i][j]); // size 0 rhombus (single cell)
13
14                for(int k = 1; ; k++){
15                    
16                    int r1 = i;
17                    int c1 = j;
18
19                    int r2 = i + k;
20                    int c2 = j - k;
21
22                    int r3 = i + 2*k;
23                    int c3 = j;
24
25                    int r4 = i + k;
26                    int c4 = j + k;
27
28                    if(r2 < 0 || c2 < 0 || r4 >= m || c4 >= n || r3 >= m)
29                        break;
30
31                    int sum = 0;
32
33                    int r = r1, c = c1;
34                    for(int d = 0; d < k; d++){
35                        sum += grid[r+d][c-d];
36                    }
37
38                    r = r2; c = c2;
39                    for(int d = 0; d < k; d++){
40                        sum += grid[r+d][c+d];
41                    }
42
43                    r = r3; c = c3;
44                    for(int d = 0; d < k; d++){
45                        sum += grid[r-d][c+d];
46                    }
47
48                    r = r4; c = c4;
49                    for(int d = 0; d < k; d++){
50                        sum += grid[r-d][c-d];
51                    }
52
53                    sums.insert(sum);
54                }
55            }
56        }
57
58        vector<int> ans;
59        for(auto it = sums.rbegin(); it != sums.rend() && ans.size() < 3; it++){
60            ans.push_back(*it);
61        }
62
63        return ans;
64    }
65};
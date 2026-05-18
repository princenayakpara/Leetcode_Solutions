// Last updated: 18/05/2026, 16:28:08
1class Solution {
2public:
3    int minJumps(vector<int>& arr) {
4        int n = arr.size();
5        if(n == 1) return 0;
6
7        unordered_map<int, vector<int>> mp;
8
9        for(int i = 0; i < n; i++) {
10            mp[arr[i]].push_back(i);
11        }
12
13        queue<int> q;
14        vector<bool> vis(n, false);
15
16        q.push(0);
17        vis[0] = true;
18
19        int steps = 0;
20
21        while(!q.empty()) {
22            int sz = q.size();
23
24            while(sz--) {
25                int i = q.front();
26                q.pop();
27
28                if(i == n - 1) return steps;
29
30                // i - 1
31                if(i - 1 >= 0 && !vis[i - 1]) {
32                    vis[i - 1] = true;
33                    q.push(i - 1);
34                }
35
36                // i + 1
37                if(i + 1 < n && !vis[i + 1]) {
38                    vis[i + 1] = true;
39                    q.push(i + 1);
40                }
41
42                // same value jumps
43                for(int idx : mp[arr[i]]) {
44                    if(!vis[idx]) {
45                        vis[idx] = true;
46                        q.push(idx);
47                    }
48                }
49
50                // clear to avoid repeated processing
51                mp[arr[i]].clear();
52            }
53
54            steps++;
55        }
56
57        return -1;
58    }
59};
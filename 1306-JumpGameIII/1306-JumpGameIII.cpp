// Last updated: 17/05/2026, 08:40:12
1class Solution {
2public:
3    bool canReach(vector<int>& arr, int start) {
4        int n = arr.size();
5        queue<int> q;
6        vector<bool> vis(n, false);
7
8        q.push(start);
9        vis[start] = true;
10
11        while (!q.empty()) {
12            int i = q.front();
13            q.pop();
14
15            if (arr[i] == 0) return true;
16
17            int left = i - arr[i];
18            int right = i + arr[i];
19
20            if (left >= 0 && !vis[left]) {
21                vis[left] = true;
22                q.push(left);
23            }
24
25            if (right < n && !vis[right]) {
26                vis[right] = true;
27                q.push(right);
28            }
29        }
30
31        return false;
32    }
33};
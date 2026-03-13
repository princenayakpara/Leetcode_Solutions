// Last updated: 13/03/2026, 16:53:18
1class Solution {
2public:
3    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
4        long long left = 1, right = 1e18;
5
6        while (left < right) {
7            long long mid = (left + right) / 2;
8            long long total = 0;
9
10            for (int t : workerTimes) {
11                long long l = 0, r = 1e6;
12
13                while (l < r) {
14                    long long m = (l + r + 1) / 2;
15                    if ((long long)t * m * (m + 1) / 2 <= mid)
16                        l = m;
17                    else
18                        r = m - 1;
19                }
20
21                total += l;
22                if (total >= mountainHeight) break;
23            }
24
25            if (total >= mountainHeight)
26                right = mid;
27            else
28                left = mid + 1;
29        }
30
31        return left;
32    }
33};
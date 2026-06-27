// Last updated: 27/06/2026, 17:24:26
1class Solution {
2public:
3    int maximumLength(vector<int>& nums) {
4        unordered_map<long long, int> cnt;
5        for (int x : nums) cnt[x]++;
6
7        int ans = 1;
8
9        // Special handling for 1
10        if (cnt.count(1))
11            ans = cnt[1] - (cnt[1] % 2 == 0);
12
13        vector<long long> vals;
14        for (auto &p : cnt) vals.push_back(p.first);
15        sort(vals.begin(), vals.end());
16
17        for (long long x : vals) {
18            if (x == 1) continue;
19
20            long long cur = x;
21            int len = 0;
22
23            while (true) {
24                if (!cnt.count(cur)) {
25                    if (len) len--;
26                    break;
27                }
28
29                if (cnt[cur] == 1) {
30                    len++;
31                    break;
32                }
33
34                len += 2;
35
36                if (cur > 1000000000LL / cur) {
37                    len--;
38                    break;
39                }
40
41                cur *= cur;
42            }
43
44            ans = max(ans, len);
45        }
46
47        return ans;
48    }
49};
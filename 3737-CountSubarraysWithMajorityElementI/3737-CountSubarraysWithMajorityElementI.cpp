// Last updated: 25/06/2026, 18:06:14
1class Solution {
2public:
3    int countMajoritySubarrays(vector<int>& nums, int target) {
4        int n = nums.size();
5        
6        // Step 1: Transform array
7        vector<int> pref(n + 1, 0);
8        for (int i = 0; i < n; i++) {
9            int val = (nums[i] == target) ? 1 : -1;
10            pref[i + 1] = pref[i] + val;
11        }
12
13        // Step 2: Coordinate Compression
14        vector<int> all = pref;
15        sort(all.begin(), all.end());
16        all.erase(unique(all.begin(), all.end()), all.end());
17
18        // Fenwick Tree
19        vector<int> bit(all.size() + 1, 0);
20
21        auto update = [&](int i) {
22            for (; i < bit.size(); i += i & -i)
23                bit[i]++;
24        };
25
26        auto query = [&](int i) {
27            int s = 0;
28            for (; i > 0; i -= i & -i)
29                s += bit[i];
30            return s;
31        };
32
33        // Step 3: Count pairs
34        long long ans = 0;
35        for (int x : pref) {
36            int idx = lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
37            
38            // count how many prefix < current
39            ans += query(idx - 1);
40            
41            update(idx);
42        }
43
44        return ans;
45    }
46};
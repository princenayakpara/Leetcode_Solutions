// Last updated: 26/06/2026, 21:59:38
1class Solution {
2public:
3    struct Fenwick {
4        int n;
5        vector<long long> bit;
6        Fenwick(int n) : n(n), bit(n + 1, 0) {}
7
8        void add(int idx, int val) {
9            for (; idx <= n; idx += idx & -idx)
10                bit[idx] += val;
11        }
12
13        long long sum(int idx) {
14            long long res = 0;
15            for (; idx > 0; idx -= idx & -idx)
16                res += bit[idx];
17            return res;
18        }
19    };
20
21    long long countMajoritySubarrays(vector<int>& nums, int target) {
22        int n = nums.size();
23
24        // Prefix sums are in [-n, n]
25        int offset = n + 1;
26        Fenwick fw(2 * n + 5);
27
28        long long ans = 0;
29        int pref = 0;
30
31        // Initial prefix sum = 0
32        fw.add(offset + 1, 1);
33
34        for (int x : nums) {
35            if (x == target)
36                pref++;
37            else
38                pref--;
39
40            // Count previous prefix sums strictly smaller than current
41            ans += fw.sum(pref + offset);
42
43            // Insert current prefix
44            fw.add(pref + offset + 1, 1);
45        }
46
47        return ans;
48    }
49};
// Last updated: 18/07/2026, 10:40:20
1class Solution {
2public:
3    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
4        int mx = *max_element(nums.begin(), nums.end());
5
6        vector<int> freq(mx + 1, 0);
7        for (int x : nums) freq[x]++;
8
9        // cntDiv[g] = numbers divisible by g
10        vector<int> cntDiv(mx + 1, 0);
11        for (int g = 1; g <= mx; g++) {
12            for (int multiple = g; multiple <= mx; multiple += g) {
13                cntDiv[g] += freq[multiple];
14            }
15        }
16
17        // exact[g] = pairs with gcd exactly g
18        vector<long long> exact(mx + 1, 0);
19
20        for (int g = mx; g >= 1; g--) {
21            long long c = cntDiv[g];
22            exact[g] = c * (c - 1) / 2;
23
24            for (int multiple = g * 2; multiple <= mx; multiple += g) {
25                exact[g] -= exact[multiple];
26            }
27        }
28
29        // Prefix of gcd values in sorted order
30        vector<long long> pref(mx + 1, 0);
31        for (int g = 1; g <= mx; g++) {
32            pref[g] = pref[g - 1] + exact[g];
33        }
34
35        vector<int> ans;
36        ans.reserve(queries.size());
37
38        for (long long q : queries) {
39            int g = lower_bound(pref.begin() + 1, pref.end(), q + 1) - pref.begin();
40            ans.push_back(g);
41        }
42
43        return ans;
44    }
45};
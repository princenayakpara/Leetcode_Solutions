// Last updated: 28/07/2026, 15:16:46
1class Solution {
2public:
3    int countQuadruplets(vector<int>& nums) {
4        int n = nums.size();
5        int ans = 0;
6        unordered_map<int, int> cnt;
7
8        for (int b = n - 3; b >= 1; --b) {
9
10           
11            for (int d = b + 2; d < n; ++d) {
12                cnt[nums[d] - nums[b + 1]]++;
13            }
14
15           
16            for (int a = 0; a < b; ++a) {
17                ans += cnt[nums[a] + nums[b]];
18            }
19        }
20
21        return ans;
22    }
23};
// Last updated: 21/08/2026, 15:18:42
1class Solution {
2public:
3    int minimumPairRemoval(vector<int>& nums) {
4        int ans = 0;
5
6        while (true) {
7            bool sorted = true;
8
9            for (int i = 1; i < nums.size(); i++) {
10                if (nums[i] < nums[i - 1]) {
11                    sorted = false;
12                    break;
13                }
14            }
15
16            if (sorted)
17                return ans;
18
19            int idx = 0;
20            int best = nums[0] + nums[1];
21
22            for (int i = 1; i + 1 < nums.size(); i++) {
23                int sum = nums[i] + nums[i + 1];
24
25                if (sum < best) {
26                    best = sum;
27                    idx = i;
28                }
29            }
30
31            nums[idx] += nums[idx + 1];
32            nums.erase(nums.begin() + idx + 1);
33            ans++;
34        }
35    }
36};
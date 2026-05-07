// Last updated: 07/05/2026, 10:13:24
1class Solution {
2public:
3    vector<int> maxValue(vector<int>& nums) {
4        int n = nums.size();
5
6        vector<int> prefMax(n), suffMin(n);
7
8        prefMax[0] = nums[0];
9        for (int i = 1; i < n; i++) {
10            prefMax[i] = max(prefMax[i - 1], nums[i]);
11        }
12
13        suffMin[n - 1] = nums[n - 1];
14        for (int i = n - 2; i >= 0; i--) {
15            suffMin[i] = min(suffMin[i + 1], nums[i]);
16        }
17
18        vector<int> ans(n);
19
20        int start = 0;
21
22        for (int i = 0; i < n - 1; i++) {
23
24            // no strict inversion crossing boundary
25            if (prefMax[i] <= suffMin[i + 1]) {
26
27                int mx = prefMax[i];
28
29                for (int j = start; j <= i; j++) {
30                    ans[j] = mx;
31                }
32
33                start = i + 1;
34            }
35        }
36
37        int mx = *max_element(nums.begin() + start, nums.end());
38
39        for (int j = start; j < n; j++) {
40            ans[j] = mx;
41        }
42
43        return ans;
44    }
45};
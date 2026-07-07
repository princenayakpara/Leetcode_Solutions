// Last updated: 07/07/2026, 18:47:14
1class Solution {
2public:
3    vector<vector<int>> threeSum(vector<int>& nums) {
4
5        vector<vector<int>> ans;
6
7        sort(nums.begin(), nums.end());
8
9        int n = nums.size();
10
11        for (int i = 0; i < n - 2; i++) {
12
13            // Skip duplicate first elements
14            if (i > 0 && nums[i] == nums[i - 1])
15                continue;
16
17            int left = i + 1;
18            int right = n - 1;
19
20            while (left < right) {
21
22                int sum = nums[i] + nums[left] + nums[right];
23
24                if (sum == 0) {
25
26                    ans.push_back({nums[i], nums[left], nums[right]});
27
28                    // Skip duplicates
29                    while (left < right && nums[left] == nums[left + 1])
30                        left++;
31
32                    while (left < right && nums[right] == nums[right - 1])
33                        right--;
34
35                    left++;
36                    right--;
37
38                }
39                else if (sum < 0) {
40                    left++;
41                }
42                else {
43                    right--;
44                }
45            }
46        }
47
48        return ans;
49    }
50};
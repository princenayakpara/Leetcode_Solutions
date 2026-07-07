// Last updated: 07/07/2026, 18:53:44
1class Solution {
2public:
3    vector<vector<int>> fourSum(vector<int>& nums, int target) {
4
5        vector<vector<int>> ans;
6        sort(nums.begin(), nums.end());
7
8        int n = nums.size();
9
10        for (int i = 0; i < n - 3; i++) {
11
12            if (i > 0 && nums[i] == nums[i - 1])
13                continue;
14
15            for (int j = i + 1; j < n - 2; j++) {
16
17                if (j > i + 1 && nums[j] == nums[j - 1])
18                    continue;
19
20                int left = j + 1;
21                int right = n - 1;
22
23                while (left < right) {
24
25                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
26
27                    if (sum == target) {
28
29                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
30
31                        while (left < right && nums[left] == nums[left + 1])
32                            left++;
33
34                        while (left < right && nums[right] == nums[right - 1])
35                            right--;
36
37                        left++;
38                        right--;
39                    }
40                    else if (sum < target) {
41                        left++;
42                    }
43                    else {
44                        right--;
45                    }
46                }
47            }
48        }
49
50        return ans;
51    }
52};
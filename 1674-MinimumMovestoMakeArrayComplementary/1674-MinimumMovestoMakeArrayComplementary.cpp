// Last updated: 13/05/2026, 15:48:44
1class Solution {
2public:
3    int minMoves(vector<int>& nums, int limit) {
4        int n = nums.size();
5        vector<int> diff(2 * limit + 2, 0);
6
7        for (int i = 0; i < n / 2; i++) {
8            int a = nums[i];
9            int b = nums[n - 1 - i];
10
11            int low = min(a, b) + 1;
12            int high = max(a, b) + limit;
13            int sum = a + b;
14
15            diff[2] += 2;
16            diff[low] -= 1;
17            diff[sum] -= 1;
18            diff[sum + 1] += 1;
19            diff[high + 1] += 1;
20        }
21
22        int ans = INT_MAX, moves = 0;
23
24        for (int s = 2; s <= 2 * limit; s++) {
25            moves += diff[s];
26            ans = min(ans, moves);
27        }
28
29        return ans;
30    }
31};
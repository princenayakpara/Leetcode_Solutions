// Last updated: 23/07/2026, 15:23:06
1class Solution {
2public:
3    int countPairs(vector<int>& nums, int k) {
4        int n = nums.size();
5        int count = 0;
6
7        for (int i = 0; i < n; i++) {
8            for (int j = i + 1; j < n; j++) {
9                if (nums[i] == nums[j] && (i * j) % k == 0) {
10                    count++;
11                }
12            }
13        }
14
15        return count;
16    }
17};
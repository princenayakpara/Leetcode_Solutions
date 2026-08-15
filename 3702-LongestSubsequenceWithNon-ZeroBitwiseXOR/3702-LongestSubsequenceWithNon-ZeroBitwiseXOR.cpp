// Last updated: 16/08/2026, 01:58:35
1class Solution {
2public:
3    int longestSubsequence(vector<int>& nums) {
4        int x = 0;
5        int nonZero = 0;
6
7        for (int num : nums) {
8            x ^= num;
9            if (num != 0)
10                nonZero++;
11        }
12
13        // Entire array has non-zero XOR.
14        if (x != 0)
15            return nums.size();
16
17        // All elements are zero -> impossible.
18        if (nonZero == 0)
19            return 0;
20
21        // XOR is zero, remove any non-zero element.
22        return nums.size() - 1;
23    }
24};
25
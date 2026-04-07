// Last updated: 07/04/2026, 09:32:17
1class Solution {
2public:
3    int majorityElement(vector<int>& nums) {
4        int candidate = 0;
5        int count = 0;
6
7        for (int num : nums) {
8            if (count == 0) {
9                candidate = num;
10            }
11
12            if (num == candidate) {
13                count++;
14            } else {
15                count--;
16            }
17        }
18
19        return candidate;
20    }
21};
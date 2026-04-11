// Last updated: 11/04/2026, 15:45:54
1class Solution {
2public:
3    int removeDuplicates(vector<int>& nums) {
4        if (nums.empty()) return 0;
5
6        int i = 0; // pointer for unique elements
7
8        for (int j = 1; j < nums.size(); j++) {
9            if (nums[j] != nums[i]) {
10                i++;
11                nums[i] = nums[j];
12            }
13        }
14
15        return i + 1; // length of unique elements
16    }
17};
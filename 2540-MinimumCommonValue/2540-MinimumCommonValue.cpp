// Last updated: 19/05/2026, 10:45:49
1class Solution {
2public:
3    int getCommon(vector<int>& nums1, vector<int>& nums2) {
4        int i = 0, j = 0;
5
6        while (i < nums1.size() && j < nums2.size()) {
7            if (nums1[i] == nums2[j]) {
8                return nums1[i];
9            }
10            else if (nums1[i] < nums2[j]) {
11                i++;
12            }
13            else {
14                j++;
15            }
16        }
17
18        return -1;
19    }
20};
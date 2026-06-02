// Last updated: 02/06/2026, 11:45:03
1class Solution {
2public:
3    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
4        vector<int> ans;
5
6        for (int num : nums1) {
7            int idx = -1;
8
9            // Find num in nums2
10            for (int i = 0; i < nums2.size(); i++) {
11                if (nums2[i] == num) {
12                    idx = i;
13                    break;
14                }
15            }
16
17            // Find next greater element
18            int nextGreater = -1;
19            for (int i = idx + 1; i < nums2.size(); i++) {
20                if (nums2[i] > num) {
21                    nextGreater = nums2[i];
22                    break;
23                }
24            }
25
26            ans.push_back(nextGreater);
27        }
28
29        return ans;
30    }
31};
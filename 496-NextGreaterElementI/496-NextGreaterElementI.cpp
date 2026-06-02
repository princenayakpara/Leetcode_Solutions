// Last updated: 02/06/2026, 11:58:14
1class Solution {
2public:
3    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
4        unordered_map<int, int> mp;
5        stack<int> st;
6
7        for (int i = nums2.size() - 1; i >= 0; i--) {
8            while (!st.empty() && st.top() <= nums2[i]) {
9                st.pop();
10            }
11
12            mp[nums2[i]] = st.empty() ? -1 : st.top();
13            st.push(nums2[i]);
14        }
15
16        vector<int> ans;
17        for (int num : nums1) {
18            ans.push_back(mp[num]);
19        }
20
21        return ans;
22    }
23};
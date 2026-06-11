// Last updated: 11/06/2026, 13:37:40
1class Solution {
2public:
3    bool containsDuplicate(vector<int>& nums) {
4        unordered_set<int> st;
5
6        for (int x : nums) {
7            if (st.count(x))
8                return true;
9            st.insert(x);
10        }
11
12        return false;
13    }
14};
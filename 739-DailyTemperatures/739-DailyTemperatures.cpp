// Last updated: 30/04/2026, 11:10:33
1class Solution {
2public:
3    vector<int> dailyTemperatures(vector<int>& temperatures) {
4        int n = temperatures.size();
5        vector<int> ans(n, 0);
6        stack<int> st; // stores indices
7
8        for(int i = 0; i < n; i++) {
9            while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
10                int idx = st.top();
11                st.pop();
12                ans[idx] = i - idx;
13            }
14            st.push(i);
15        }
16
17        return ans;
18    }
19};
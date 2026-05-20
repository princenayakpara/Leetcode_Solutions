// Last updated: 20/05/2026, 18:14:20
1class Solution {
2public:
3    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
4        int n = A.size();
5        vector<int> ans(n);
6        
7        unordered_set<int> s1, s2;
8        int common = 0;
9
10        for (int i = 0; i < n; i++) {
11            
12            // If A[i] already appeared in B prefix
13            if (s2.count(A[i])) {
14                common++;
15            }
16
17            // If B[i] already appeared in A prefix
18            // and A[i] != B[i] to avoid double counting
19            if (s1.count(B[i]) && A[i] != B[i]) {
20                common++;
21            }
22
23            // Same element added at same index
24            if (A[i] == B[i]) {
25                common++;
26            }
27
28            s1.insert(A[i]);
29            s2.insert(B[i]);
30
31            ans[i] = common;
32        }
33
34        return ans;
35    }
36};
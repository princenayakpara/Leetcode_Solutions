// Last updated: 21/05/2026, 19:30:28
1class Solution {
2public:
3    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
4        unordered_set<string> prefixes;
5
6        // Store all prefixes of numbers in arr1
7        for (int num : arr1) {
8            string s = to_string(num);
9            string pref = "";
10
11            for (char c : s) {
12                pref += c;
13                prefixes.insert(pref);
14            }
15        }
16
17        int ans = 0;
18
19        // Check prefixes from arr2
20        for (int num : arr2) {
21            string s = to_string(num);
22            string pref = "";
23
24            for (char c : s) {
25                pref += c;
26
27                if (prefixes.count(pref)) {
28                    ans = max(ans, (int)pref.size());
29                }
30            }
31        }
32
33        return ans;
34    }
35};
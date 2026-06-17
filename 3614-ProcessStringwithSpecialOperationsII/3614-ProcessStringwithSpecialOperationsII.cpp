// Last updated: 17/06/2026, 10:42:43
1class Solution {
2public:
3    char processStr(string s, long long k) {
4        int n = s.size();
5
6        vector<long long> len(n + 1, 0);
7
8        for (int i = 0; i < n; i++) {
9            char c = s[i];
10
11            if ('a' <= c && c <= 'z') {
12                len[i + 1] = min((long long)4e18, len[i] + 1);
13            }
14            else if (c == '*') {
15                len[i + 1] = max(0LL, len[i] - 1);
16            }
17            else if (c == '#') {
18                len[i + 1] = min((long long)4e18, len[i] * 2);
19            }
20            else { // '%'
21                len[i + 1] = len[i];
22            }
23        }
24
25        if (k >= len[n]) return '.';
26
27        for (int i = n - 1; i >= 0; i--) {
28            char c = s[i];
29            long long prevLen = len[i];
30
31            if ('a' <= c && c <= 'z') {
32                if (k == prevLen) return c;
33            }
34            else if (c == '*') {
35                // deletion: positions before deletion stay unchanged
36            }
37            else if (c == '#') {
38                if (k >= prevLen) k -= prevLen;
39            }
40            else { // '%'
41                k = prevLen - 1 - k;
42            }
43        }
44
45        return '.';
46    }
47};
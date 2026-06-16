// Last updated: 16/06/2026, 13:37:43
1class Solution {
2public:
3    int compareVersion(string version1, string version2) {
4        int i = 0, j = 0;
5        int n = version1.size(), m = version2.size();
6
7        while (i < n || j < m) {
8            long long num1 = 0, num2 = 0;
9
10            while (i < n && version1[i] != '.') {
11                num1 = num1 * 10 + (version1[i] - '0');
12                i++;
13            }
14
15            while (j < m && version2[j] != '.') {
16                num2 = num2 * 10 + (version2[j] - '0');
17                j++;
18            }
19
20            if (num1 < num2) return -1;
21            if (num1 > num2) return 1;
22
23            i++; 
24            j++; 
25        }
26
27        return 0;
28    }
29};
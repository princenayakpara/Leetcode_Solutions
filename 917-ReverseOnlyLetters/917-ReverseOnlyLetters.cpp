// Last updated: 07/05/2026, 21:57:26
1class Solution {
2public:
3    string capitalizeTitle(string title) {
4        int n = title.size();
5
6        for (char &c : title) {
7            c = tolower(c);
8        }
9
10        int i = 0;
11
12        while (i < n) {
13            int start = i;
14
15            while (i < n && title[i] != ' ') {
16                i++;
17            }
18
19            int len = i - start;
20
21            if (len > 2) {
22                title[start] = toupper(title[start]);
23            }
24
25            i++;
26        }
27
28        return title;
29    }
30};
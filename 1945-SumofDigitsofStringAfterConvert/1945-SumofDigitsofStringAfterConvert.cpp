// Last updated: 08/05/2026, 15:59:20
1class Solution {
2public:
3    int minMaxDifference(int num) {
4        string s = to_string(num);
5
6        // Make maximum number
7        string maxi = s;
8        char chMax = 0;
9
10        for(char c : s) {
11            if(c != '9') {
12                chMax = c;
13                break;
14            }
15        }
16
17        if(chMax) {
18            for(char &c : maxi) {
19                if(c == chMax) {
20                    c = '9';
21                }
22            }
23        }
24
25        // Make minimum number
26        string mini = s;
27        char chMin = s[0];
28
29        for(char &c : mini) {
30            if(c == chMin) {
31                c = '0';
32            }
33        }
34
35        return stoi(maxi) - stoi(mini);
36    }
37};
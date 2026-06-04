// Last updated: 04/06/2026, 11:02:38
1class Solution {
2public:
3    string decodeString(string s) {
4        stack<int> countStack;
5        stack<string> strStack;
6
7        string curr = "";
8        int num = 0;
9
10        for (char ch : s) {
11            if (isdigit(ch)) {
12                num = num * 10 + (ch - '0');
13            }
14            else if (ch == '[') {
15                countStack.push(num);
16                strStack.push(curr);
17
18                num = 0;
19                curr = "";
20            }
21            else if (ch == ']') {
22                int repeat = countStack.top();
23                countStack.pop();
24
25                string prev = strStack.top();
26                strStack.pop();
27
28                string temp = "";
29                for (int i = 0; i < repeat; i++) {
30                    temp += curr;
31                }
32
33                curr = prev + temp;
34            }
35            else {
36                curr += ch;
37            }
38        }
39
40        return curr;
41    }
42};
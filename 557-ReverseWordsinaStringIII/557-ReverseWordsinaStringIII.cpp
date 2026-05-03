// Last updated: 03/05/2026, 21:56:39
1class Solution {
2public:
3    string reverseWords(string s) {
4        string result = "";
5        string temp = "";
6
7        for (int i = 0; i < s.length(); i++) {
8            if (s[i] != ' ') {
9                temp += s[i];
10            } else {
11                reverse(temp.begin(), temp.end());
12                result += temp + " ";
13                temp = "";
14            }
15        }
16        
17        reverse(temp.begin(), temp.end());
18        result += temp;
19
20        return result;
21    }
22};
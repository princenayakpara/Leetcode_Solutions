// Last updated: 01/05/2026, 16:39:44
1class Solution {
2public:
3    string defangIPaddr(string address) {
4        string result = "";
5        
6        for (char c : address) {
7            if (c == '.') {
8                result += "[.]";
9            } else {
10                result += c;
11            }
12        }
13        
14        return result;
15    }
16};
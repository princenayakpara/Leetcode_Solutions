// Last updated: 04/06/2026, 10:55:53
1class Solution {
2public:
3    string gcdOfStrings(string str1, string str2) {
4        if(str1 + str2 != str2 + str1)
5            return "";
6
7        int len = gcd(str1.length(), str2.length());
8
9        return str1.substr(0, len);
10    }
11};
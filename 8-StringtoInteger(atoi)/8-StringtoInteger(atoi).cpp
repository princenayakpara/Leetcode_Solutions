// Last updated: 18/08/2026, 15:03:35
1class Solution {
2public:
3    int myAtoi(string s) {
4        int i = 0, n = s.size();
5        while (i < n && s[i] == ' ') i++;
6        int sign = 1;
7        if (i < n && (s[i] == '+' || s[i] == '-')) {
8            if (s[i] == '-') sign = -1;
9            i++;
10        }
11        long  num = 0;
12        while (i < n && isdigit(s[i])) {
13            num = num * 10 + (s[i] - '0');
14            if (sign == 1 && num > INT_MAX)
15                return INT_MAX;   
16            if (sign == -1 && -num < INT_MIN)
17                return INT_MIN; 
18            i++;
19        }
20        return (int)(sign * num);
21    }
22};
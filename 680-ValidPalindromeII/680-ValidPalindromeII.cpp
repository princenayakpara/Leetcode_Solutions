// Last updated: 07/07/2026, 19:03:57
1class Solution {
2public:
3    bool check(string &s, int left, int right) {
4        while (left < right) {
5            if (s[left] != s[right])
6                return false;
7            left++;
8            right--;
9        }
10        return true;
11    }
12
13    bool validPalindrome(string s) {
14        int left = 0;
15        int right = s.size() - 1;
16
17        while (left < right) {
18            if (s[left] != s[right]) {
19                return check(s, left + 1, right) ||
20                       check(s, left, right - 1);
21            }
22            left++;
23            right--;
24        }
25
26        return true;
27    }
28};
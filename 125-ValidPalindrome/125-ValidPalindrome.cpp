// Last updated: 24/04/2026, 09:19:51
1class Solution {
2public:
3    bool isPalindrome(string s) {
4        int left = 0, right = s.length() - 1;
5
6        while (left < right) {
7            while (left < right && !isalnum(s[left])) left++;
8            while (left < right && !isalnum(s[right])) right--;
9
10            if (tolower(s[left]) != tolower(s[right])) {
11                return false;
12            }
13
14            left++;
15            right--;
16        }
17
18        return true;
19    }
20};
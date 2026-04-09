// Last updated: 09/04/2026, 09:29:21
1class Solution {
2public:
3    void reverseString(vector<char>& s) {
4        int left = 0;
5        int right = s.size() - 1;
6
7        while (left < right) {
8            swap(s[left], s[right]);
9            left++;
10            right--;
11        }
12    }
13};
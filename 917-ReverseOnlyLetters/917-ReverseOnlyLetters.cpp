// Last updated: 09/04/2026, 10:33:23
1class Solution {
2public:
3    string reverseOnlyLetters(string s) {
4        int left = 0, right = s.size() - 1;
5
6        while (left < right) {
7            if (!isalpha(s[left])) {
8                left++;
9            } 
10            else if (!isalpha(s[right])) {
11                right--;
12            } 
13            else {
14                swap(s[left], s[right]);
15                left++;
16                right--;
17            }
18        }
19        
20        return s;
21    }
22};
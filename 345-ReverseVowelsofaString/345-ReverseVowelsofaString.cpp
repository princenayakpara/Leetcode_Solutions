// Last updated: 09/04/2026, 09:58:50
1class Solution {
2public:
3    string reverseVowels(string s) {
4        int left = 0, right = s.size() - 1;
5        
6        auto isVowel = [](char c) {
7            c = tolower(c);
8            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
9        };
10        
11        while (left < right) {
12            if (!isVowel(s[left])) {
13                left++;
14            } else if (!isVowel(s[right])) {
15                right--;
16            } else {
17                swap(s[left], s[right]);
18                left++;
19                right--;
20            }
21        }
22        
23        return s;
24    }
25};
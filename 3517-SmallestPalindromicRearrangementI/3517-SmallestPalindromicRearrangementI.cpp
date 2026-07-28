// Last updated: 28/07/2026, 14:53:15
1class Solution {
2public:
3    string smallestPalindrome(string s) {
4        vector<int> freq(26, 0);
5
6        for (char c : s)
7            freq[c - 'a']++;
8
9        string left = "";
10        char mid = '\0';
11
12        for (int i = 0; i < 26; i++) {
13            left.append(freq[i] / 2, char('a' + i));
14            if (freq[i] % 2)
15                mid = char('a' + i);
16        }
17
18        string right = left;
19        reverse(right.begin(), right.end());
20
21        if (mid)
22            return left + string(1, mid) + right;
23        return left + right;
24    }
25};
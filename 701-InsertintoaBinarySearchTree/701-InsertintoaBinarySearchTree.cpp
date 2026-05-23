// Last updated: 23/05/2026, 16:12:57
1class Solution {
2public:
3    bool isVowel(char ch) {
4        return ch=='a' || ch=='e' || ch=='i' || 
5               ch=='o' || ch=='u';
6    }
7    
8    int maxVowels(string s, int k) {
9         int cnt = 0;
10        int ans = 0;
11
12        // first window
13        for(int i = 0; i < k; i++) {
14            if(isVowel(s[i]))
15                cnt++;
16        }
17
18        ans = cnt;
19
20        // sliding window
21        for(int i = k; i < s.size(); i++) {
22
23            // remove left character
24            if(isVowel(s[i-k]))
25                cnt--;
26
27            // add new character
28            if(isVowel(s[i]))
29                cnt++;
30
31            ans = max(ans, cnt);
32        }
33
34        return ans;
35    }
36};
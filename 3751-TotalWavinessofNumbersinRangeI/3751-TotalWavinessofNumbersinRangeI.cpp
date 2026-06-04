// Last updated: 04/06/2026, 10:45:10
1class Solution {
2public:
3    int waviness(int x) {
4        string s = to_string(x);
5        int n = s.size();
6
7        if (n < 3) return 0;
8
9        int cnt = 0;
10
11        for (int i = 1; i < n - 1; i++) {
12            if (s[i] > s[i - 1] && s[i] > s[i + 1])
13                cnt++; // peak
14            else if (s[i] < s[i - 1] && s[i] < s[i + 1])
15                cnt++; // valley
16        }
17
18        return cnt;
19    }
20
21    int totalWaviness(int num1, int num2) {
22        int ans = 0;
23
24        for (int x = num1; x <= num2; x++) {
25            ans += waviness(x);
26        }
27
28        return ans;
29    }
30};
// Last updated: 29/07/2026, 13:03:56
1class Solution {
2public:
3    string smallestPalindrome(string s, int k) {
4        const int CAP = 1000000;
5        vector<int> freq(26, 0);
6        for (char c : s) freq[c - 'a']++;
7
8        string mid = "";
9        vector<int> half(26, 0);
10        int halfLen = 0;
11        for (int i = 0; i < 26; i++) {
12            if (freq[i] & 1) mid.push_back(char('a' + i));
13            half[i] = freq[i] / 2;
14            halfLen += half[i];
15        }
16
17        // ---------- primes + SPF ----------
18        vector<int> spf(halfLen + 1);
19        vector<int> primes;
20        for (int i = 2; i <= halfLen; i++) {
21            if (!spf[i]) {
22                spf[i] = i;
23                primes.push_back(i);
24            }
25            for (int p : primes) {
26                if (p > spf[i] || 1LL * p * i > halfLen) break;
27                spf[p * i] = p;
28            }
29        }
30
31        int P = primes.size();
32        vector<vector<unsigned short>> factExp(halfLen + 1,
33                                               vector<unsigned short>(P, 0));
34
35        vector<int> idx(halfLen + 1, -1);
36        for (int i = 0; i < P; i++) idx[primes[i]] = i;
37
38        for (int i = 1; i <= halfLen; i++) {
39            factExp[i] = factExp[i - 1];
40            int x = i;
41            while (x > 1) {
42                int p = spf[x];
43                factExp[i][idx[p]]++;
44                x /= p;
45            }
46        }
47
48        auto combCap = [&](int n, int r) -> int {
49            if (r < 0 || r > n) return 0;
50            r = min(r, n - r);
51            if (r == 0) return 1;
52
53            unsigned long long res = 1;
54            for (int i = 0; i < P; i++) {
55                int e = factExp[n][i] - factExp[r][i] - factExp[n - r][i];
56                while (e--) {
57                    if (res > (unsigned long long)CAP / primes[i]) return CAP;
58                    res *= primes[i];
59                    if (res >= CAP) return CAP;
60                }
61            }
62            return (int)res;
63        };
64
65        auto countWays = [&](const vector<int> &cnt) -> int {
66            unsigned long long res = 1;
67            int used = 0;
68            for (int c : cnt) {
69                if (c == 0) continue;
70                int ways = combCap(used + c, c);
71                if (ways >= CAP) return CAP;
72                if (res > (unsigned long long)CAP / ways) return CAP;
73                res *= ways;
74                if (res >= CAP) return CAP;
75                used += c;
76            }
77            return (int)res;
78        };
79
80        if (countWays(half) < k) return "";
81
82        string left;
83        for (int pos = 0; pos < halfLen; pos++) {
84            for (int ch = 0; ch < 26; ch++) {
85                if (half[ch] == 0) continue;
86                half[ch]--;
87                int ways = countWays(half);
88                if (ways >= k) {
89                    left.push_back(char('a' + ch));
90                    break;
91                } else {
92                    k -= ways;
93                    half[ch]++;
94                }
95            }
96        }
97
98        string right = left;
99        reverse(right.begin(), right.end());
100        return left + mid + right;
101    }
102};
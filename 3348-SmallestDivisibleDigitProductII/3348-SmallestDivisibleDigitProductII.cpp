// Last updated: 08/08/2026, 10:46:16
1class Solution {
2public:
3    string smallestNumber(string num, long long t) {
4        // Factor counts for digits 0-9: map digit -> {2:cnt, 3:cnt, 5:cnt, 7:cnt}
5        vector<map<int, int>> kFactorCounts(10);
6        kFactorCounts[2] = {{2, 1}};
7        kFactorCounts[3] = {{3, 1}};
8        kFactorCounts[4] = {{2, 2}};
9        kFactorCounts[5] = {{5, 1}};
10        kFactorCounts[6] = {{2, 1}, {3, 1}};
11        kFactorCounts[7] = {{7, 1}};
12        kFactorCounts[8] = {{2, 3}};
13        kFactorCounts[9] = {{3, 2}};
14        // 0 and 1 stay empty
15
16        auto getPrimeCount = [&](long long x) -> pair<map<int, int>, bool> {
17            map<int, int> count{{2, 0}, {3, 0}, {5, 0}, {7, 0}};
18            for (int p : {2, 3, 5, 7}) {
19                while (x % p == 0) {
20                    x /= p;
21                    count[p]++;
22                }
23            }
24            return {count, x == 1};
25        };
26
27        auto [primeCount, isDivisible] = getPrimeCount(t);
28        if (!isDivisible) return "-1";
29
30        auto getFactorCount = [&](map<int, int> count) -> map<int, int> {
31            map<int, int> res;
32            int count8 = count[2] / 3;
33            int remaining2 = count[2] % 3;
34            int count9 = count[3] / 2;
35            int count3 = count[3] % 2;
36            int count4 = remaining2 / 2;
37            int count2 = remaining2 % 2;
38            int count6 = 0;
39            if (count2 == 1 && count3 == 1) {
40                count2 = 0;
41                count3 = 0;
42                count6 = 1;
43            }
44            if (count3 == 1 && count4 == 1) {
45                count2 = 1;
46                count6 = 1;
47                count3 = 0;
48                count4 = 0;
49            }
50            res[2] = count2;
51            res[3] = count3;
52            res[4] = count4;
53            res[5] = count[5];
54            res[6] = count6;
55            res[7] = count[7];
56            res[8] = count8;
57            res[9] = count9;
58            return res;
59        };
60
61        auto construct = [&](const map<int, int>& factors) -> string {
62            string res;
63            for (int d = 2; d <= 9; d++) {
64                if (factors.count(d)) {
65                    res += string(factors.at(d), '0' + d);
66                }
67            }
68            return res;
69        };
70
71        auto sumValues = [&](const map<int, int>& count) -> int {
72            int s = 0;
73            for (auto& [k, v] : count) s += v;
74            return s;
75        };
76
77        auto isSubset = [&](const map<int, int>& a, const map<int, int>& b) -> bool {
78            for (auto& [k, v] : a) {
79                if (b.count(k) == 0 || b.at(k) < v) return false;
80            }
81            return true;
82        };
83
84        auto subtract = [&](map<int, int> a, const map<int, int>& b) -> map<int, int> {
85            for (auto& [k, v] : b) {
86                a[k] = max(0, a[k] - v);
87            }
88            return a;
89        };
90
91        auto getPrimeCountFromString = [&](const string& s) -> map<int, int> {
92            map<int, int> count{{2, 0}, {3, 0}, {5, 0}, {7, 0}};
93            for (char ch : s) {
94                int d = ch - '0';
95                for (auto& [p, f] : kFactorCounts[d]) {
96                    count[p] += f;
97                }
98            }
99            return count;
100        };
101
102        map<int, int> factorCount = getFactorCount(primeCount);
103        if (sumValues(factorCount) > (int)num.size()) {
104            return construct(factorCount);
105        }
106
107        map<int, int> primeCountPrefix = getPrimeCountFromString(num);
108        int firstZeroIndex = num.find('0');
109        if (firstZeroIndex == string::npos) {
110            firstZeroIndex = num.size();
111            if (isSubset(primeCount, primeCountPrefix)) {
112                return num;
113            }
114        }
115
116        for (int i = (int)num.size() - 1; i >= 0; i--) {
117            int d = num[i] - '0';
118            primeCountPrefix = subtract(primeCountPrefix, kFactorCounts[d]);
119            int spaceAfter = (int)num.size() - 1 - i;
120            if (i > firstZeroIndex) continue;
121
122            for (int bigger = d + 1; bigger <= 9; bigger++) {
123                map<int, int> remaining = subtract(subtract(primeCount, primeCountPrefix), kFactorCounts[bigger]);
124                map<int, int> factorsAfter = getFactorCount(remaining);
125                if (sumValues(factorsAfter) <= spaceAfter) {
126                    int fillOnes = spaceAfter - sumValues(factorsAfter);
127                    return num.substr(0, i) + to_string(bigger) + string(fillOnes, '1') + construct(factorsAfter);
128                }
129            }
130        }
131
132        // Need one extra digit
133        map<int, int> factorsExt = getFactorCount(primeCount);
134        int ones = (int)num.size() + 1 - sumValues(factorsExt);
135        return string(ones, '1') + construct(factorsExt);
136    }
137};
// Last updated: 08/05/2026, 09:49:08
1class Solution {
2public:
3    bool isPrime(int x) {
4        if (x < 2) return false;
5        for (int i = 2; i * i <= x; i++) {
6            if (x % i == 0) return false;
7        }
8        return true;
9    }
10
11    vector<int> getPrimeFactors(int x) {
12        vector<int> factors;
13
14        for (int p = 2; p * p <= x; p++) {
15            if (x % p == 0) {
16                factors.push_back(p);
17
18                while (x % p == 0)
19                    x /= p;
20            }
21        }
22
23        if (x > 1)
24            factors.push_back(x);
25
26        return factors;
27    }
28
29    int minJumps(vector<int>& nums) {
30        int n = nums.size();
31
32        unordered_map<int, vector<int>> divisible;
33
34        // Store indices divisible by each prime factor
35        for (int i = 0; i < n; i++) {
36            vector<int> factors = getPrimeFactors(nums[i]);
37
38            for (int p : factors) {
39                divisible[p].push_back(i);
40            }
41        }
42
43        queue<int> q;
44        vector<int> dist(n, -1);
45
46        q.push(0);
47        dist[0] = 0;
48
49        unordered_set<int> usedPrime;
50
51        while (!q.empty()) {
52            int i = q.front();
53            q.pop();
54
55            int steps = dist[i];
56
57            if (i == n - 1)
58                return steps;
59
60            // adjacent left
61            if (i - 1 >= 0 && dist[i - 1] == -1) {
62                dist[i - 1] = steps + 1;
63                q.push(i - 1);
64            }
65
66            // adjacent right
67            if (i + 1 < n && dist[i + 1] == -1) {
68                dist[i + 1] = steps + 1;
69                q.push(i + 1);
70            }
71
72            // teleportation
73            if (isPrime(nums[i]) && !usedPrime.count(nums[i])) {
74                int p = nums[i];
75
76                for (int idx : divisible[p]) {
77                    if (dist[idx] == -1) {
78                        dist[idx] = steps + 1;
79                        q.push(idx);
80                    }
81                }
82
83                usedPrime.insert(p);
84            }
85        }
86
87        return -1;
88    }
89};
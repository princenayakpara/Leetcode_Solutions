// Last updated: 08/05/2026, 16:43:21
1class Solution {
2public:
3    int getSum(int n) {
4        int sum = 0;
5
6        while(n) {
7            int d = n % 10;
8            sum += d * d;
9            n /= 10;
10        }
11
12        return sum;
13    }
14
15    bool isHappy(int n) {
16        unordered_set<int> seen;
17
18        while(n != 1 && !seen.count(n)) {
19            seen.insert(n);
20            n = getSum(n);
21        }
22
23        return n == 1;
24    }
25};
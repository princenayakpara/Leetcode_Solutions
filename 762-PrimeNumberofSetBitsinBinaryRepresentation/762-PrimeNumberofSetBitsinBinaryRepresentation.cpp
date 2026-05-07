// Last updated: 07/05/2026, 17:25:37
1class Solution {
2public:
3    bool isPrime(int n) {
4        if(n < 2) return false;
5
6        for(int i = 2; i * i <= n; i++) {
7            if(n % i == 0) {
8                return false;
9            }
10        }
11
12        return true;
13    }
14
15    int countPrimeSetBits(int left, int right) {
16        int count = 0;
17
18        for(int i = left; i <= right; i++) {
19            int setBits = __builtin_popcount(i);
20
21            if(isPrime(setBits)) {
22                count++;
23            }
24        }
25
26        return count;
27    }
28};
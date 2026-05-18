// Last updated: 18/05/2026, 16:33:56
1class Solution {
2public:
3    bool checkPerfectNumber(int num) {
4        if(num == 1) return false;
5
6        int sum = 1;
7
8        for(int i = 2; i * i <= num; i++) {
9            if(num % i == 0) {
10                sum += i;
11
12                if(i != num / i) {
13                    sum += num / i;
14                }
15            }
16        }
17
18        return sum == num;
19    }
20};
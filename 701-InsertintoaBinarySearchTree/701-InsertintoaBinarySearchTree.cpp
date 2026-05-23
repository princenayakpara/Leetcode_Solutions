// Last updated: 23/05/2026, 16:24:06
1class Solution {
2public:
3    int rev(int n) {
4        int r = 0;
5
6        while(n) {
7            r = r * 10 + n % 10;
8            n /= 10;
9        }
10
11        return r;
12    }
13    bool sumOfNumberAndReverse(int num) {
14        for(int i = 0; i <= num; i++) {
15            if(i + rev(i) == num)
16                return true;
17        }
18
19        return false;
20    }
21};
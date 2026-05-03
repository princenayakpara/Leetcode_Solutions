// Last updated: 03/05/2026, 12:18:48
1class Solution {
2public:
3    int countDigits(int num) {
4        int original = num;
5        int count = 0;
6
7        while(num>0){
8        int digit = num % 10;
9        if(digit != 0 && original % digit == 0) {
10                count++;
11            }
12
13            num = num / 10;
14        }
15        return count;
16    }
17};
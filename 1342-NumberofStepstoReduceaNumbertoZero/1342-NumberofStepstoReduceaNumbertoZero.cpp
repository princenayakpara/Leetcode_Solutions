// Last updated: 03/05/2026, 12:06:53
1class Solution {
2public:
3    int numberOfSteps(int num) {
4        int count = 0;
5
6        while(num!=0) {
7            if(num%2==0) {
8                num = num/2;
9            } else {
10                num = num-1;
11            }
12            count++;
13        }
14
15        return count;
16    }
17};
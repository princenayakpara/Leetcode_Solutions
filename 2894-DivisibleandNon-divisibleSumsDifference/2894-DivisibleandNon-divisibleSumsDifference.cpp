// Last updated: 30/07/2026, 15:24:41
1class Solution {
2public:
3    int differenceOfSums(int n, int m) {
4        int sum1 = 0;
5        int sum2 = 0;
6
7        for(int i = 1; i<=n; i++){
8            if(i % m ==0){
9                sum2 = sum2 + i;;
10                }else{
11                    sum1 =sum1 + i;
12                }
13            }
14        return sum1 - sum2;
15    }
16};
// Last updated: 13/06/2026, 11:49:12
1class Solution {
2public:
3    int digitFrequencyScore(int n) {
4       int ans = 0;
5
6       while(n>0){
7        ans+= n % 10;
8        n/= 10;
9       }
10       return ans;
11    }
12};
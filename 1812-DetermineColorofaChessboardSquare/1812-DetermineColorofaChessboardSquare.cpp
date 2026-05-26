// Last updated: 27/05/2026, 02:39:51
1class Solution {
2public:
3    int sumBase(int n, int k) {
4        int sum = 0;
5        while(n>0){
6            sum+=n%k;
7            n/=k;
8        }
9        return sum;
10    }
11};
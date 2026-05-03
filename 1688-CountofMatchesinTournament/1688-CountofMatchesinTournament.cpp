// Last updated: 03/05/2026, 15:35:24
1class Solution {
2public:
3    int numberOfMatches(int n) {
4        int sum =0;
5        while(n >1){
6            if(n%2 ==0){
7                sum += n/2;
8                n = n = n/2;
9            }
10            else{
11                sum += (n-1)/2;
12                n = (n-1)/2 + 1;
13            }
14        }
15
16        return sum;
17    }
18};
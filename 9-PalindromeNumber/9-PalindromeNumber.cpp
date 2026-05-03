// Last updated: 03/05/2026, 12:32:30
1class Solution {
2public:
3    bool isPalindrome(int x) {
4        if(x<0){
5            return false;
6        }
7        else{
8            long long int num = 0;
9            int ans = x;
10            while(x>=1){
11                int temp = x % 10;
12                num = num * 10 + temp;
13                x = x/10;
14            }
15            return num == ans;
16        }
17    }
18};
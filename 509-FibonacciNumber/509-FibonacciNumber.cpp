// Last updated: 23/05/2026, 22:40:22
1class Solution {
2public:
3    int fib(int n) {
4        int a=0,b=1,q,c=0;
5        if(n==0)
6        return 0;
7        if(n==1)
8        return 1;
9        for(int i=2;i<=n;i++){
10        q=a+b;
11        a=b;
12        b=q;}
13        return q;
14    }
15};
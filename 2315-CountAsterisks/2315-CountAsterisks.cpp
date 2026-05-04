// Last updated: 04/05/2026, 11:17:08
1class Solution {
2public:
3    int countAsterisks(string s) {
4        int count = 0;
5        int countPair = 0;
6        for(char ch : s){
7        if(ch == '|'){
8            countPair++;
9        }
10        if(ch=='*'&& countPair%2==0){
11            count++;
12        }
13        }
14        return count;
15    }
16};
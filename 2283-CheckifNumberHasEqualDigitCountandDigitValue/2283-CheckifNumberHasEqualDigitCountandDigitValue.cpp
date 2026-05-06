// Last updated: 07/05/2026, 00:05:29
1class Solution {
2public:
3    bool digitCount(string num) {
4        vector<int> freq(10, 0);
5
6        for(char c : num){
7            freq[c - '0']++;
8        }
9
10        for(int i = 0; i < num.size(); i++){
11            if(freq[i] != num[i] - '0'){
12                return false;
13            }
14        }
15
16        return true;
17    }
18};
// Last updated: 15/04/2026, 10:52:27
1class Solution {
2public:
3    int firstUniqChar(string s) {
4        vector<int> freq(26, 0);
5
6        for(char c : s){
7            freq[c - 'a']++;
8        }
9
10        for(int i = 0; i < s.size(); i++){
11            if(freq[s[i] - 'a'] == 1){
12                return i;
13            }
14        }
15
16        return -1; 
17    }
18};
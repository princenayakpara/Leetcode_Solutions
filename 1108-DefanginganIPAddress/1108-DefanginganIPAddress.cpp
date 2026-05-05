// Last updated: 05/05/2026, 16:06:53
1class Solution {
2public:
3    string defangIPaddr(string address) {
4        string result;
5        for(char c : address){
6            if(c=='.'){
7                result+="[.]";
8            }
9            else{
10                result+=c;
11            }
12        }
13            return result;
14        }
15};
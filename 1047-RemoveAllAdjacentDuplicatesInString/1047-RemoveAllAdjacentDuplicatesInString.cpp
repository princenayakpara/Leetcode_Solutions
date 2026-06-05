// Last updated: 05/06/2026, 14:35:30
1class Solution {
2public:
3    string removeDuplicates(string s) {
4        string res="";
5        for(char ch : s){
6            if(!res.empty() && res.back() == ch){
7                res.pop_back();
8            }else{
9                res.push_back(ch);
10            }
11        }
12        return res;
13    }
14};
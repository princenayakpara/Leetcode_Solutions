// Last updated: 07/07/2026, 19:05:44
1class Solution {
2public:
3    bool valid(string& s,int l,int r){
4        while(l<r){
5            if(s[l]!=s[r])return false;
6            l++;
7            r--;
8        }
9        return true;
10    }
11    bool validPalindrome(string s) {
12        int l=0,r=s.size()-1;
13        while(l<r){
14            if(s[l]!=s[r])return valid(s,l+1,r)||valid(s,l,r-1);
15            l++;
16            r--;
17        }
18        return true;
19    
20    }
21};
// Last updated: 15/03/2026, 01:20:36
1class Solution {
2public:
3    void solve(int n, string &curr, vector<string> &res) {
4        if(curr.size() == n){
5            res.push_back(curr);
6            return;
7        }
8
9        for(char c : {'a','b','c'}) {
10            if(curr.empty() || curr.back() != c){
11                curr.push_back(c);
12                solve(n, curr, res);
13                curr.pop_back();
14            }
15        }
16    }
17
18    string getHappyString(int n, int k) {
19        vector<string> res;
20        string curr = "";
21
22        solve(n, curr, res);
23
24        if(k > res.size()) return "";
25        return res[k-1];
26    }
27};
28
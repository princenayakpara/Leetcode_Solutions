// Last updated: 13/06/2026, 08:59:41
1class Solution {
2public:
3    string mapWordWeights(vector<string>& words, vector<int>& weights) {
4        string ans;
5
6        for (string &word : words) {
7            int sum = 0;
8
9            for (char c : word) {
10                sum += weights[c - 'a'];
11            }
12
13            int mod = sum % 26;
14            ans.push_back('z' - mod);
15        }
16
17        return ans;
18    }
19};
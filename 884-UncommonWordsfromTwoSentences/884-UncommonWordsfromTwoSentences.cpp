// Last updated: 22/05/2026, 10:13:42
1class Solution {
2public:
3    vector<string> uncommonFromSentences(string s1, string s2) {
4        unordered_map<string, int>mp;
5
6        stringstream ss1(s1), ss2(s2);
7        string word;
8
9        while(ss1 >> word){
10            mp[word]++;
11        }
12
13        while(ss2 >> word){
14            mp[word]++;
15        }
16
17        vector<string> ans;
18
19        for(auto it : mp){
20            if(it.second == 1){
21                ans.push_back(it.first);
22            }
23        }
24        return ans;
25    }
26};
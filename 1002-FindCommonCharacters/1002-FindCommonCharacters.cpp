// Last updated: 13/06/2026, 11:24:48
1class Solution {
2public:
3    vector<string> commonChars(vector<string>& words) {
4        string res = words[0];
5
6        for (int j = 0; j < res.size(); ) {
7            char ch = res[j];
8            bool common = true;
9
10            for (int i = 1; i < words.size(); i++) {
11                int pos = words[i].find(ch);
12
13                if (pos != string::npos) {
14                    words[i].erase(pos, 1); // remove one occurrence
15                } else {
16                    common = false;
17                    break;
18                }
19            }
20
21            if (!common) {
22                res.erase(j, 1); // remove from result
23            } else {
24                j++;
25            }
26        }
27
28        vector<string> ans;
29        for (char ch : res) {
30            ans.push_back(string(1, ch));
31        }
32
33        return ans;
34    }
35};
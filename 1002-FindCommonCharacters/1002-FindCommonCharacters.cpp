// Last updated: 13/06/2026, 11:31:17
1class Solution {
2public:
3    vector<string> commonChars(vector<string>& words) {
4        vector<string> res;
5
6        for (char ch : words[0]) {
7            string temp = "";
8            temp += ch;
9
10            bool found = true;
11
12            for (int j = 1; j < words.size(); j++) {
13                size_t pos = words[j].find(ch);
14
15                if (pos == string::npos) {
16                    found = false;
17                    break;
18                }
19
20                words[j].erase(pos, 1);
21            }
22
23            if (found) {
24                res.push_back(temp);
25            }
26        }
27
28        return res;
29    }
30};
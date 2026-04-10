// Last updated: 10/04/2026, 15:57:29
1class Solution {
2public:
3    string reverseWords(string s) {
4        vector<string> words;
5        string temp = "";
6
7        for (int i = 0; i < s.size(); i++) {
8            if (s[i] == ' ') {
9                if (!temp.empty()) {
10                    words.push_back(temp);
11                    temp = "";
12                }
13            } else {
14                temp += s[i];
15            }
16        }
17// edge case
18        if (!temp.empty()) {
19            words.push_back(temp);
20        }
21
22        reverse(words.begin(), words.end());
23        
24        string result = "";
25        for (int i = 0; i < words.size(); i++) {
26            result += words[i];
27            if (i != words.size() - 1) result += " ";
28        }
29
30        return result;
31    }
32};
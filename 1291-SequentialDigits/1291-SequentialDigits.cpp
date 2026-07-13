// Last updated: 13/07/2026, 14:19:02
1class Solution {
2public:
3    vector<int> sequentialDigits(int low, int high) {
4        vector<int> ans;
5        string digits = "123456789";
6
7        for (int len = 2; len <= 9; len++) {
8            for (int i = 0; i + len <= 9; i++) {
9                int num = stoi(digits.substr(i, len));
10                if (num >= low && num <= high)
11                    ans.push_back(num);
12            }
13        }
14
15        return ans;
16    }
17};
// Last updated: 11/05/2026, 09:51:29
1class Solution {
2public:
3    vector<int> separateDigits(vector<int>& nums) {
4        vector<int> result;
5
6        for (int num : nums) {
7            vector<int> temp;
8
9            // Extract digits
10            while (num > 0) {
11                temp.push_back(num % 10);
12                num /= 10;
13            }
14
15            // Reverse to maintain order
16            reverse(temp.begin(), temp.end());
17
18            // Add to result
19            for (int d : temp) {
20                result.push_back(d);
21            }
22        }
23
24        return result;
25    }
26};
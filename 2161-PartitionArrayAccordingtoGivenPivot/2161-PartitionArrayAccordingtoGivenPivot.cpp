// Last updated: 08/06/2026, 09:11:52
1class Solution {
2public:
3    vector<int> pivotArray(vector<int>& nums, int pivot) {
4        vector<int> less, equal, greater;
5
6        for (int num : nums) {
7            if (num < pivot) {
8                less.push_back(num);
9            } 
10            else if (num == pivot) {
11                equal.push_back(num);
12            } 
13            else {
14                greater.push_back(num);
15            }
16        }
17
18        vector<int> ans;
19        
20        ans.insert(ans.end(), less.begin(), less.end());
21        ans.insert(ans.end(), equal.begin(), equal.end());
22        ans.insert(ans.end(), greater.begin(), greater.end());
23
24        return ans;
25    }
26};